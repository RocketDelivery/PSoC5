#include "FreeRTOS.h"
#include "task.h"
#include "project.h"

static StaticTask_t _idleTask;
static StackType_t _idleTaskStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize)
{
    *ppxIdleTaskTCBBuffer = &_idleTask;
    *ppxIdleTaskStackBuffer = _idleTaskStack;
    *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}

static StaticTask_t _timerTask;
static StackType_t _timerTaskStack[configMINIMAL_STACK_SIZE];

void vApplicationGetTimerTaskMemory(StaticTask_t **ppxTimerTaskTCBBuffer, StackType_t **ppxTimerTaskStackBuffer, uint32_t *pulTimerTaskStackSize)
{
    *ppxTimerTaskTCBBuffer = &_timerTask;
    *ppxTimerTaskStackBuffer = _timerTaskStack;
    *pulTimerTaskStackSize = configMINIMAL_STACK_SIZE;
}

void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName )
{
    (void)xTask;
    (void)pcTaskName;
    
    LED4Pin_Write(1);
    taskDISABLE_INTERRUPTS();
    for (;;);
}

static StaticTask_t _blinkLedTask;
static StackType_t _blinkLedTaskStack[configMINIMAL_STACK_SIZE];

void blinkLED(void* data)
{
    for(;;)
    {
        LED1Pin_Write(~LED1Pin_ReadDataReg());
        vTaskDelay(250);
    }
    vTaskDelete(NULL);
}

int main(void)
{
    // Cypress runtime defines its own interrupt vector and puts it in a defined memory region
    // Copied from https://github.com/FreeRTOS/FreeRTOS/blob/main/FreeRTOS/Demo/CORTEX_CY8C5588_PSoC_Creator_GCC/FreeRTOS_Demo.cydsn/main.c
    extern void xPortPendSVHandler( void );
    extern void xPortSysTickHandler( void );
    extern void vPortSVCHandler( void );
    extern cyisraddress CyRamVectors[];
    
    CyRamVectors[11] = (cyisraddress)vPortSVCHandler;
	CyRamVectors[14] = (cyisraddress)xPortPendSVHandler;
	CyRamVectors[15] = (cyisraddress)xPortSysTickHandler;

    xTaskCreateStatic(blinkLED, "BlinkLED", configMINIMAL_STACK_SIZE, NULL, 1, _blinkLedTaskStack, &_blinkLedTask);
    
    vTaskStartScheduler();
    
    for (;;);
}
