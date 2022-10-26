/*******************************************************************************
* File Name: I2CTemp_MASTER.c
* Version 3.50
*
* Description:
*  This file provides the source code of APIs for the I2C component master mode.
*
*******************************************************************************
* Copyright 2012-2015, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "I2CTemp_PVT.h"

#if(I2CTemp_MODE_MASTER_ENABLED)

/**********************************
*      System variables
**********************************/

volatile uint8 I2CTemp_mstrStatus;     /* Master Status byte  */
volatile uint8 I2CTemp_mstrControl;    /* Master Control byte */

/* Transmit buffer variables */
volatile uint8 * I2CTemp_mstrRdBufPtr;     /* Pointer to Master Read buffer */
volatile uint8   I2CTemp_mstrRdBufSize;    /* Master Read buffer size       */
volatile uint8   I2CTemp_mstrRdBufIndex;   /* Master Read buffer Index      */

/* Receive buffer variables */
volatile uint8 * I2CTemp_mstrWrBufPtr;     /* Pointer to Master Write buffer */
volatile uint8   I2CTemp_mstrWrBufSize;    /* Master Write buffer size       */
volatile uint8   I2CTemp_mstrWrBufIndex;   /* Master Write buffer Index      */


/*******************************************************************************
* Function Name: I2CTemp_MasterWriteBuf
********************************************************************************
*
* Summary:
*  Automatically writes an entire buffer of data to a slave device. Once the
*  data transfer is initiated by this function, further data transfer is handled
*  by the included ISR in byte by byte mode.
*
* Parameters:
*  slaveAddr: 7-bit slave address.
*  xferData:  Pointer to buffer of data to be sent.
*  cnt:       Size of buffer to send.
*  mode:      Transfer mode defines: start or restart condition generation at
*             begin of the transfer and complete the transfer or halt before
*             generating a stop.
*
* Return:
*  Status error - Zero means no errors.
*
* Side Effects:
*  The included ISR will start a transfer after a start or restart condition is
*  generated.
*
* Global variables:
*  I2CTemp_mstrStatus  - The global variable used to store a current
*                                 status of the I2C Master.
*  I2CTemp_state       - The global variable used to store a current
*                                 state of the software FSM.
*  I2CTemp_mstrControl - The global variable used to control the master
*                                 end of a transaction with or without Stop
*                                 generation.
*  I2CTemp_mstrWrBufPtr - The global variable used to store a pointer
*                                  to the master write buffer.
*  I2CTemp_mstrWrBufIndex - The global variable used to store current
*                                    index within the master write buffer.
*  I2CTemp_mstrWrBufSize - The global variable used to store a master
*                                   write buffer size.
*
* Reentrant:
*  No
*
*******************************************************************************/
uint8 I2CTemp_MasterWriteBuf(uint8 slaveAddress, uint8 * wrData, uint8 cnt, uint8 mode)
      
{
    uint8 errStatus;

    errStatus = I2CTemp_MSTR_NOT_READY;

    if(NULL != wrData)
    {
        /* Check I2C state to allow transfer: valid states are IDLE or HALT */
        if(I2CTemp_SM_IDLE == I2CTemp_state)
        {
            /* Master is ready for transaction: check if bus is free */
            if(I2CTemp_CHECK_BUS_FREE(I2CTemp_MCSR_REG))
            {
                errStatus = I2CTemp_MSTR_NO_ERROR;
            }
            else
            {
                errStatus = I2CTemp_MSTR_BUS_BUSY;
            }
        }
        else if(I2CTemp_SM_MSTR_HALT == I2CTemp_state)
        {
            /* Master is ready and waiting for ReStart */
            errStatus = I2CTemp_MSTR_NO_ERROR;

            I2CTemp_ClearPendingInt();
            I2CTemp_mstrStatus &= (uint8) ~I2CTemp_MSTAT_XFER_HALT;
        }
        else
        {
            /* errStatus = I2CTemp_MSTR_NOT_READY was send before */
        }

        if(I2CTemp_MSTR_NO_ERROR == errStatus)
        {
            /* Set state to start write transaction */
            I2CTemp_state = I2CTemp_SM_MSTR_WR_ADDR;

            /* Prepare write buffer */
            I2CTemp_mstrWrBufIndex = 0u;
            I2CTemp_mstrWrBufSize  = cnt;
            I2CTemp_mstrWrBufPtr   = (volatile uint8 *) wrData;

            /* Set end of transaction flag: Stop or Halt (following ReStart) */
            I2CTemp_mstrControl = mode;

            /* Clear write status history */
            I2CTemp_mstrStatus &= (uint8) ~I2CTemp_MSTAT_WR_CMPLT;

            /* Hardware actions: write address and generate Start or ReStart */
            I2CTemp_DATA_REG = (uint8) (slaveAddress << I2CTemp_SLAVE_ADDR_SHIFT);

            if(I2CTemp_CHECK_RESTART(mode))
            {
                I2CTemp_GENERATE_RESTART;
            }
            else
            {
                I2CTemp_GENERATE_START;
            }

            /* Enable interrupt to complete transfer */
            I2CTemp_EnableInt();
        }
    }

    return(errStatus);
}


/*******************************************************************************
* Function Name: I2CTemp_MasterReadBuf
********************************************************************************
*
* Summary:
*  Automatically writes an entire buffer of data to a slave device. Once the
*  data transfer is initiated by this function, further data transfer is handled
*  by the included ISR in byte by byte mode.
*
* Parameters:
*  slaveAddr: 7-bit slave address.
*  xferData:  Pointer to buffer where to put data from slave.
*  cnt:       Size of buffer to read.
*  mode:      Transfer mode defines: start or restart condition generation at
*             begin of the transfer and complete the transfer or halt before
*             generating a stop.
*
* Return:
*  Status error - Zero means no errors.
*
* Side Effects:
*  The included ISR will start a transfer after start or restart condition is
*  generated.
*
* Global variables:
*  I2CTemp_mstrStatus  - The global variable used to store a current
*                                 status of the I2C Master.
*  I2CTemp_state       - The global variable used to store a current
*                                 state of the software FSM.
*  I2CTemp_mstrControl - The global variable used to control the master
*                                 end of a transaction with or without
*                                 Stop generation.
*  I2CTemp_mstrRdBufPtr - The global variable used to store a pointer
*                                  to the master write buffer.
*  I2CTemp_mstrRdBufIndex - The global variable  used to store a
*                                    current index within the master
*                                    write buffer.
*  I2CTemp_mstrRdBufSize - The global variable used to store a master
*                                   write buffer size.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 I2CTemp_MasterReadBuf(uint8 slaveAddress, uint8 * rdData, uint8 cnt, uint8 mode)
      
{
    uint8 errStatus;

    errStatus = I2CTemp_MSTR_NOT_READY;

    if(NULL != rdData)
    {
        /* Check I2C state to allow transfer: valid states are IDLE or HALT */
        if(I2CTemp_SM_IDLE == I2CTemp_state)
        {
            /* Master is ready to transaction: check if bus is free */
            if(I2CTemp_CHECK_BUS_FREE(I2CTemp_MCSR_REG))
            {
                errStatus = I2CTemp_MSTR_NO_ERROR;
            }
            else
            {
                errStatus = I2CTemp_MSTR_BUS_BUSY;
            }
        }
        else if(I2CTemp_SM_MSTR_HALT == I2CTemp_state)
        {
            /* Master is ready and waiting for ReStart */
            errStatus = I2CTemp_MSTR_NO_ERROR;

            I2CTemp_ClearPendingInt();
            I2CTemp_mstrStatus &= (uint8) ~I2CTemp_MSTAT_XFER_HALT;
        }
        else
        {
            /* errStatus = I2CTemp_MSTR_NOT_READY was set before */
        }

        if(I2CTemp_MSTR_NO_ERROR == errStatus)
        {
            /* Set state to start write transaction */
            I2CTemp_state = I2CTemp_SM_MSTR_RD_ADDR;

            /* Prepare read buffer */
            I2CTemp_mstrRdBufIndex  = 0u;
            I2CTemp_mstrRdBufSize   = cnt;
            I2CTemp_mstrRdBufPtr    = (volatile uint8 *) rdData;

            /* Set end of transaction flag: Stop or Halt (following ReStart) */
            I2CTemp_mstrControl = mode;

            /* Clear read status history */
            I2CTemp_mstrStatus &= (uint8) ~I2CTemp_MSTAT_RD_CMPLT;

            /* Hardware actions: write address and generate Start or ReStart */
            I2CTemp_DATA_REG = ((uint8) (slaveAddress << I2CTemp_SLAVE_ADDR_SHIFT) |
                                                  I2CTemp_READ_FLAG);

            if(I2CTemp_CHECK_RESTART(mode))
            {
                I2CTemp_GENERATE_RESTART;
            }
            else
            {
                I2CTemp_GENERATE_START;
            }

            /* Enable interrupt to complete transfer */
            I2CTemp_EnableInt();
        }
    }

    return(errStatus);
}


/*******************************************************************************
* Function Name: I2CTemp_MasterSendStart
********************************************************************************
*
* Summary:
*  Generates Start condition and sends slave address with read/write bit.
*
* Parameters:
*  slaveAddress:  7-bit slave address.
*  R_nW:          Zero, send write command, non-zero send read command.
*
* Return:
*  Status error - Zero means no errors.
*
* Side Effects:
*  This function is entered without a "byte complete" bit set in the I2C_CSR
*  register. It does not exit until it is set.
*
* Global variables:
*  I2CTemp_state - The global variable used to store a current state of
*                           the software FSM.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 I2CTemp_MasterSendStart(uint8 slaveAddress, uint8 R_nW)
      
{
    uint8 errStatus;

    errStatus = I2CTemp_MSTR_NOT_READY;

    /* If IDLE, check if bus is free */
    if(I2CTemp_SM_IDLE == I2CTemp_state)
    {
        /* If bus is free, generate Start condition */
        if(I2CTemp_CHECK_BUS_FREE(I2CTemp_MCSR_REG))
        {
            /* Disable interrupt for manual master operation */
            I2CTemp_DisableInt();

            /* Set address and read/write flag */
            slaveAddress = (uint8) (slaveAddress << I2CTemp_SLAVE_ADDR_SHIFT);
            if(0u != R_nW)
            {
                slaveAddress |= I2CTemp_READ_FLAG;
                I2CTemp_state = I2CTemp_SM_MSTR_RD_ADDR;
            }
            else
            {
                I2CTemp_state = I2CTemp_SM_MSTR_WR_ADDR;
            }

            /* Hardware actions: write address and generate Start */
            I2CTemp_DATA_REG = slaveAddress;
            I2CTemp_GENERATE_START_MANUAL;

            /* Wait until address is transferred */
            while(I2CTemp_WAIT_BYTE_COMPLETE(I2CTemp_CSR_REG))
            {
            }

        #if(I2CTemp_MODE_MULTI_MASTER_SLAVE_ENABLED)
            if(I2CTemp_CHECK_START_GEN(I2CTemp_MCSR_REG))
            {
                I2CTemp_CLEAR_START_GEN;

                /* Start condition was not generated: reset FSM to IDLE */
                I2CTemp_state = I2CTemp_SM_IDLE;
                errStatus = I2CTemp_MSTR_ERR_ABORT_START_GEN;
            }
            else
        #endif /* (I2CTemp_MODE_MULTI_MASTER_SLAVE_ENABLED) */

        #if(I2CTemp_MODE_MULTI_MASTER_ENABLED)
            if(I2CTemp_CHECK_LOST_ARB(I2CTemp_CSR_REG))
            {
                I2CTemp_BUS_RELEASE_MANUAL;

                /* Master lost arbitrage: reset FSM to IDLE */
                I2CTemp_state = I2CTemp_SM_IDLE;
                errStatus = I2CTemp_MSTR_ERR_ARB_LOST;
            }
            else
        #endif /* (I2CTemp_MODE_MULTI_MASTER_ENABLED) */

            if(I2CTemp_CHECK_ADDR_NAK(I2CTemp_CSR_REG))
            {
                /* Address has been NACKed: reset FSM to IDLE */
                I2CTemp_state = I2CTemp_SM_IDLE;
                errStatus = I2CTemp_MSTR_ERR_LB_NAK;
            }
            else
            {
                /* Start was sent without errors */
                errStatus = I2CTemp_MSTR_NO_ERROR;
            }
        }
        else
        {
            errStatus = I2CTemp_MSTR_BUS_BUSY;
        }
    }

    return(errStatus);
}


/*******************************************************************************
* Function Name: I2CTemp_MasterSendRestart
********************************************************************************
*
* Summary:
*  Generates ReStart condition and sends slave address with read/write bit.
*
* Parameters:
*  slaveAddress:  7-bit slave address.
*  R_nW:          Zero, send write command, non-zero send read command.
*
* Return:
*  Status error - Zero means no errors.
*
* Side Effects:
*  This function is entered without a "byte complete" bit set in the I2C_CSR
*  register. It does not exit until it is set.
*
* Global variables:
*  I2CTemp_state - The global variable used to store a current state of
*                           the software FSM.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 I2CTemp_MasterSendRestart(uint8 slaveAddress, uint8 R_nW)
      
{
    uint8 errStatus;

    errStatus = I2CTemp_MSTR_NOT_READY;

    /* Check if START condition was generated */
    if(I2CTemp_CHECK_MASTER_MODE(I2CTemp_MCSR_REG))
    {
        /* Set address and read/write flag */
        slaveAddress = (uint8) (slaveAddress << I2CTemp_SLAVE_ADDR_SHIFT);
        if(0u != R_nW)
        {
            slaveAddress |= I2CTemp_READ_FLAG;
            I2CTemp_state = I2CTemp_SM_MSTR_RD_ADDR;
        }
        else
        {
            I2CTemp_state = I2CTemp_SM_MSTR_WR_ADDR;
        }

        /* Hardware actions: write address and generate ReStart */
        I2CTemp_DATA_REG = slaveAddress;
        I2CTemp_GENERATE_RESTART_MANUAL;

        /* Wait until address has been transferred */
        while(I2CTemp_WAIT_BYTE_COMPLETE(I2CTemp_CSR_REG))
        {
        }

    #if(I2CTemp_MODE_MULTI_MASTER_ENABLED)
        if(I2CTemp_CHECK_LOST_ARB(I2CTemp_CSR_REG))
        {
            I2CTemp_BUS_RELEASE_MANUAL;

            /* Master lost arbitrage: reset FSM to IDLE */
            I2CTemp_state = I2CTemp_SM_IDLE;
            errStatus = I2CTemp_MSTR_ERR_ARB_LOST;
        }
        else
    #endif /* (I2CTemp_MODE_MULTI_MASTER_ENABLED) */

        if(I2CTemp_CHECK_ADDR_NAK(I2CTemp_CSR_REG))
        {
            /* Address has been NACKed: reset FSM to IDLE */
            I2CTemp_state = I2CTemp_SM_IDLE;
            errStatus = I2CTemp_MSTR_ERR_LB_NAK;
        }
        else
        {
            /* ReStart was sent without errors */
            errStatus = I2CTemp_MSTR_NO_ERROR;
        }
    }

    return(errStatus);
}


/*******************************************************************************
* Function Name: I2CTemp_MasterSendStop
********************************************************************************
*
* Summary:
*  Generates I2C Stop condition on bus. Function do nothing if Start or Restart
*  condition was failed before call this function.
*
* Parameters:
*  None.
*
* Return:
*  Status error - Zero means no errors.
*
* Side Effects:
*  Stop generation is required to complete the transaction.
*  This function does not wait until a Stop condition is generated.
*
* Global variables:
*  I2CTemp_state - The global variable used to store a current state of
*                           the software FSM.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 I2CTemp_MasterSendStop(void) 
{
    uint8 errStatus;

    errStatus = I2CTemp_MSTR_NOT_READY;

    /* Check if master is active on bus */
    if(I2CTemp_CHECK_MASTER_MODE(I2CTemp_MCSR_REG))
    {
        I2CTemp_GENERATE_STOP_MANUAL;
        I2CTemp_state = I2CTemp_SM_IDLE;

        /* Wait until stop has been generated */
        while(I2CTemp_WAIT_STOP_COMPLETE(I2CTemp_CSR_REG))
        {
        }

        errStatus = I2CTemp_MSTR_NO_ERROR;

    #if(I2CTemp_MODE_MULTI_MASTER_ENABLED)
        if(I2CTemp_CHECK_LOST_ARB(I2CTemp_CSR_REG))
        {
            I2CTemp_BUS_RELEASE_MANUAL;

            /* NACK was generated by instead Stop */
            errStatus = I2CTemp_MSTR_ERR_ARB_LOST;
        }
    #endif /* (I2CTemp_MODE_MULTI_MASTER_ENABLED) */
    }

    return(errStatus);
}


/*******************************************************************************
* Function Name: I2CTemp_MasterWriteByte
********************************************************************************
*
* Summary:
*  Sends one byte to a slave. A valid Start or ReStart condition must be
*  generated before this call this function. Function do nothing if Start or
*  Restart condition was failed before call this function.
*
* Parameters:
*  data:  The data byte to send to the slave.
*
* Return:
*  Status error - Zero means no errors.
*
* Side Effects:
*  This function is entered without a "byte complete" bit set in the I2C_CSR
*  register. It does not exit until it is set.
*
* Global variables:
*  I2CTemp_state - The global variable used to store a current state of
*                           the software FSM.
*
*******************************************************************************/
uint8 I2CTemp_MasterWriteByte(uint8 theByte) 
{
    uint8 errStatus;

    errStatus = I2CTemp_MSTR_NOT_READY;

    /* Check if START condition was generated */
    if(I2CTemp_CHECK_MASTER_MODE(I2CTemp_MCSR_REG))
    {
        I2CTemp_DATA_REG = theByte;   /* Write DATA register */
        I2CTemp_TRANSMIT_DATA_MANUAL; /* Set transmit mode   */
        I2CTemp_state = I2CTemp_SM_MSTR_WR_DATA;

        /* Wait until data byte has been transmitted */
        while(I2CTemp_WAIT_BYTE_COMPLETE(I2CTemp_CSR_REG))
        {
        }

    #if(I2CTemp_MODE_MULTI_MASTER_ENABLED)
        if(I2CTemp_CHECK_LOST_ARB(I2CTemp_CSR_REG))
        {
            I2CTemp_BUS_RELEASE_MANUAL;

            /* Master lost arbitrage: reset FSM to IDLE */
            I2CTemp_state = I2CTemp_SM_IDLE;
            errStatus = I2CTemp_MSTR_ERR_ARB_LOST;
        }
        /* Check LRB bit */
        else
    #endif /* (I2CTemp_MODE_MULTI_MASTER_ENABLED) */

        if(I2CTemp_CHECK_DATA_ACK(I2CTemp_CSR_REG))
        {
            I2CTemp_state = I2CTemp_SM_MSTR_HALT;
            errStatus = I2CTemp_MSTR_NO_ERROR;
        }
        else
        {
            I2CTemp_state = I2CTemp_SM_MSTR_HALT;
            errStatus = I2CTemp_MSTR_ERR_LB_NAK;
        }
    }

    return(errStatus);
}


/*******************************************************************************
* Function Name: I2CTemp_MasterReadByte
********************************************************************************
*
* Summary:
*  Reads one byte from a slave and ACK or NACK the transfer. A valid Start or
*  ReStart condition must be generated before this call this function. Function
*  do nothing if Start or Restart condition was failed before call this
*  function.
*
* Parameters:
*  acknNack:  Zero, response with NACK, if non-zero response with ACK.
*
* Return:
*  Byte read from slave.
*
* Side Effects:
*  This function is entered without a "byte complete" bit set in the I2C_CSR
*  register. It does not exit until it is set.
*
* Global variables:
*  I2CTemp_state - The global variable used to store a current
*                           state of the software FSM.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 I2CTemp_MasterReadByte(uint8 acknNak) 
{
    uint8 theByte;

    theByte = 0u;

    /* Check if START condition was generated */
    if(I2CTemp_CHECK_MASTER_MODE(I2CTemp_MCSR_REG))
    {
        /* When address phase needs to release bus and receive byte,
        * then decide ACK or NACK
        */
        if(I2CTemp_SM_MSTR_RD_ADDR == I2CTemp_state)
        {
            I2CTemp_READY_TO_READ_MANUAL;
            I2CTemp_state = I2CTemp_SM_MSTR_RD_DATA;
        }

        /* Wait until data byte has been received */
        while(I2CTemp_WAIT_BYTE_COMPLETE(I2CTemp_CSR_REG))
        {
        }

        theByte = I2CTemp_DATA_REG;

        /* Command ACK to receive next byte and continue transfer.
        *  Do nothing for NACK. The NACK will be generated by
        *  Stop or ReStart routine.
        */
        if(acknNak != 0u) /* Generate ACK */
        {
            I2CTemp_ACK_AND_RECEIVE_MANUAL;
        }
        else              /* Do nothing for the follwong NACK */
        {
            I2CTemp_state = I2CTemp_SM_MSTR_HALT;
        }
    }

    return(theByte);
}


/*******************************************************************************
* Function Name: I2CTemp_MasterStatus
********************************************************************************
*
* Summary:
*  Returns the master's communication status.
*
* Parameters:
*  None.
*
* Return:
*  Current status of I2C master.
*
* Global variables:
*  I2CTemp_mstrStatus - The global variable used to store a current
*                                status of the I2C Master.
*
*******************************************************************************/
uint8 I2CTemp_MasterStatus(void) 
{
    uint8 status;

    I2CTemp_DisableInt(); /* Lock from interrupt */

    /* Read master status */
    status = I2CTemp_mstrStatus;

    if (I2CTemp_CHECK_SM_MASTER)
    {
        /* Set transfer in progress flag in status */
        status |= I2CTemp_MSTAT_XFER_INP;
    }

    I2CTemp_EnableInt(); /* Release lock */

    return (status);
}


/*******************************************************************************
* Function Name: I2CTemp_MasterClearStatus
********************************************************************************
*
* Summary:
*  Clears all status flags and returns the master status.
*
* Parameters:
*  None.
*
* Return:
*  Current status of I2C master.
*
* Global variables:
*  I2CTemp_mstrStatus - The global variable used to store a current
*                                status of the I2C Master.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 I2CTemp_MasterClearStatus(void) 
{
    uint8 status;

    I2CTemp_DisableInt(); /* Lock from interrupt */

    /* Read and clear master status */
    status = I2CTemp_mstrStatus;
    I2CTemp_mstrStatus = I2CTemp_MSTAT_CLEAR;

    I2CTemp_EnableInt(); /* Release lock */

    return (status);
}


/*******************************************************************************
* Function Name: I2CTemp_MasterGetReadBufSize
********************************************************************************
*
* Summary:
*  Returns the amount of bytes that has been transferred with an
*  I2C_MasterReadBuf command.
*
* Parameters:
*  None.
*
* Return:
*  Byte count of transfer. If the transfer is not yet complete, it will return
*  the byte count transferred so far.
*
* Global variables:
*  I2CTemp_mstrRdBufIndex - The global variable stores current index
*                                    within the master read buffer.
*
*******************************************************************************/
uint8 I2CTemp_MasterGetReadBufSize(void) 
{
    return (I2CTemp_mstrRdBufIndex);
}


/*******************************************************************************
* Function Name: I2CTemp_MasterGetWriteBufSize
********************************************************************************
*
* Summary:
*  Returns the amount of bytes that has been transferred with an
*  I2C_MasterWriteBuf command.
*
* Parameters:
*  None.
*
* Return:
*  Byte count of transfer. If the transfer is not yet complete, it will return
*  the byte count transferred so far.
*
* Global variables:
*  I2CTemp_mstrWrBufIndex -  The global variable used to stores current
*                                     index within master write buffer.
*
*******************************************************************************/
uint8 I2CTemp_MasterGetWriteBufSize(void) 
{
    return (I2CTemp_mstrWrBufIndex);
}


/*******************************************************************************
* Function Name: I2CTemp_MasterClearReadBuf
********************************************************************************
*
* Summary:
*  Resets the read buffer pointer back to the first byte in the buffer.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  I2CTemp_mstrRdBufIndex - The global variable used to stores current
*                                    index within master read buffer.
*  I2CTemp_mstrStatus - The global variable used to store a current
*                                status of the I2C Master.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void I2CTemp_MasterClearReadBuf(void) 
{
    I2CTemp_DisableInt(); /* Lock from interrupt */

    I2CTemp_mstrRdBufIndex = 0u;
    I2CTemp_mstrStatus    &= (uint8) ~I2CTemp_MSTAT_RD_CMPLT;

    I2CTemp_EnableInt(); /* Release lock */
}


/*******************************************************************************
* Function Name: I2CTemp_MasterClearWriteBuf
********************************************************************************
*
* Summary:
*  Resets the write buffer pointer back to the first byte in the buffer.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  I2CTemp_mstrRdBufIndex - The global variable used to stote current
*                                    index within master read buffer.
*  I2CTemp_mstrStatus - The global variable used to store a current
*                                status of the I2C Master.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void I2CTemp_MasterClearWriteBuf(void) 
{
    I2CTemp_DisableInt(); /* Lock from interrupt */

    I2CTemp_mstrWrBufIndex = 0u;
    I2CTemp_mstrStatus    &= (uint8) ~I2CTemp_MSTAT_WR_CMPLT;

    I2CTemp_EnableInt(); /* Release lock */
}

#endif /* (I2CTemp_MODE_MASTER_ENABLED) */


/* [] END OF FILE */