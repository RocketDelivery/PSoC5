#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "project.h"
#include <stddef.h>
#include "temperature.h"

#define UPSTREAM_QUEUE_LENGTH 2
#define DOWNSTREAM_QUEUE_LENGTH 2

static StaticTask_t _i2ctempTask;
static StackType_t _i2cTempTaskStack[configMINIMAL_STACK_SIZE];

// UpStream -> "us"
static QueueHandle_t _usQueue;
static StaticQueue_t _usQueueStruct;
static TaskHandle_t _usQueueBuffer[UPSTREAM_QUEUE_LENGTH];

// DownStream -> "ds"
struct DSQueueItem
{
    TaskHandle_t callerTask;
    uint16_t tempVal;
};

static QueueHandle_t _dsQueue;
static StaticQueue_t _dsQueueStruct;
static struct DSQueueItem _dsQueueBuffer[DOWNSTREAM_QUEUE_LENGTH];

static uint8_t _readMCP9808(uint16_t* tempRaw)
{
    #if I2CTemp_MSTR_NO_ERROR != 0
    #error I2CTemp_MSTR_NO_ERROR is not zero    
    #endif
    
    // Default I2C address of sensor is 0x18 (see back of the sensor PCB)
    const uint8 kSensorI2CAddr = 0x18;
    // From MCP9808 datasheet
    const uint8 kTempRegisterIdx = 5;
    
    uint8 result = 0;
    
    result = I2CTemp_MasterSendStart(kSensorI2CAddr, 0);
    if (result != I2CTemp_MSTR_NO_ERROR)
    {
        return result;   
    }
    
    result = I2CTemp_MasterWriteByte(kTempRegisterIdx);
    if (result != I2CTemp_MSTR_NO_ERROR)
    {
        return result;   
    }
    
    result = I2CTemp_MasterSendRestart(kSensorI2CAddr, 1);
    if (result != I2CTemp_MSTR_NO_ERROR)
    {
        return result;   
    }
    
    *tempRaw = 0;
    *tempRaw |= I2CTemp_MasterReadByte(I2CTemp_ACK_DATA) << 8;
    *tempRaw |= I2CTemp_MasterReadByte(I2CTemp_NAK_DATA);
    
    result = I2CTemp_MasterSendStop();
    if (result != I2CTemp_MSTR_NO_ERROR)
    {
        return result;
    }
    
    // Only the lowest 13 bits are used
    *tempRaw &= 0x1FFF;
    
    return 0;
}

static void _mcp9808ReadTask(void* data)
{
    (void)data;
    
    TaskHandle_t callerTask;
    struct DSQueueItem dsItem;
    
    for (;;)
    {
        BaseType_t result = xQueueReceive(_usQueue, &callerTask, portMAX_DELAY); 
        if (result != pdTRUE)
        {
            continue;
        }
        
        if (_readMCP9808(&dsItem.tempVal))
        {
            // Set all bits to 1 to indiate error
            dsItem.tempVal = -1;   
        }
        dsItem.callerTask = callerTask;
        
        xQueueSendToBack(_dsQueue, &dsItem, portMAX_DELAY);
    }
}

void temperatureInit()
{
    I2CTemp_Start();
    
    xTaskCreateStatic(
        _mcp9808ReadTask, 
        "MCP9808Read", 
        configMINIMAL_STACK_SIZE, 
        NULL, 
        4, 
        _i2cTempTaskStack, 
        &_i2ctempTask);
    
    _usQueue = xQueueCreateStatic(
        UPSTREAM_QUEUE_LENGTH, 
        sizeof(TaskHandle_t), 
        (uint8_t*)_usQueueBuffer, 
        &_usQueueStruct);
    configASSERT(_usQueue != NULL);
    
    _dsQueue = xQueueCreateStatic(
        DOWNSTREAM_QUEUE_LENGTH,
        sizeof(struct DSQueueItem),
        (uint8_t*)_dsQueueBuffer,
        &_dsQueueStruct);
    configASSERT(_dsQueue != NULL);
}

uint16 temperatureReadBlocking()
{
    TaskHandle_t ownTask = xTaskGetCurrentTaskHandle();
    struct DSQueueItem dsItem;
    
    xQueueSendToBack(_usQueue, &ownTask, portMAX_DELAY);
    
    while ((xQueuePeek(_dsQueue, &dsItem, portMAX_DELAY)), dsItem.callerTask != ownTask)
    {
        taskYIELD();
    }
    if (xQueueReceive(_dsQueue, &dsItem, 0) != pdTRUE)
    {
        // There should have been an item that corresponds to the caller
        // but couldn't receive anything
        configASSERT(0);
        return -1;
    }
    configASSERT(dsItem.callerTask == ownTask);
    
    return dsItem.tempVal;
}
