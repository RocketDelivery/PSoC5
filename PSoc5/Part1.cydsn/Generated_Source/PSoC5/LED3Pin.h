/*******************************************************************************
* File Name: LED3Pin.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_LED3Pin_H) /* Pins LED3Pin_H */
#define CY_PINS_LED3Pin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LED3Pin_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LED3Pin__PORT == 15 && ((LED3Pin__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    LED3Pin_Write(uint8 value);
void    LED3Pin_SetDriveMode(uint8 mode);
uint8   LED3Pin_ReadDataReg(void);
uint8   LED3Pin_Read(void);
void    LED3Pin_SetInterruptMode(uint16 position, uint16 mode);
uint8   LED3Pin_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the LED3Pin_SetDriveMode() function.
     *  @{
     */
        #define LED3Pin_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define LED3Pin_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define LED3Pin_DM_RES_UP          PIN_DM_RES_UP
        #define LED3Pin_DM_RES_DWN         PIN_DM_RES_DWN
        #define LED3Pin_DM_OD_LO           PIN_DM_OD_LO
        #define LED3Pin_DM_OD_HI           PIN_DM_OD_HI
        #define LED3Pin_DM_STRONG          PIN_DM_STRONG
        #define LED3Pin_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define LED3Pin_MASK               LED3Pin__MASK
#define LED3Pin_SHIFT              LED3Pin__SHIFT
#define LED3Pin_WIDTH              1u

/* Interrupt constants */
#if defined(LED3Pin__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LED3Pin_SetInterruptMode() function.
     *  @{
     */
        #define LED3Pin_INTR_NONE      (uint16)(0x0000u)
        #define LED3Pin_INTR_RISING    (uint16)(0x0001u)
        #define LED3Pin_INTR_FALLING   (uint16)(0x0002u)
        #define LED3Pin_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define LED3Pin_INTR_MASK      (0x01u) 
#endif /* (LED3Pin__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LED3Pin_PS                     (* (reg8 *) LED3Pin__PS)
/* Data Register */
#define LED3Pin_DR                     (* (reg8 *) LED3Pin__DR)
/* Port Number */
#define LED3Pin_PRT_NUM                (* (reg8 *) LED3Pin__PRT) 
/* Connect to Analog Globals */                                                  
#define LED3Pin_AG                     (* (reg8 *) LED3Pin__AG)                       
/* Analog MUX bux enable */
#define LED3Pin_AMUX                   (* (reg8 *) LED3Pin__AMUX) 
/* Bidirectional Enable */                                                        
#define LED3Pin_BIE                    (* (reg8 *) LED3Pin__BIE)
/* Bit-mask for Aliased Register Access */
#define LED3Pin_BIT_MASK               (* (reg8 *) LED3Pin__BIT_MASK)
/* Bypass Enable */
#define LED3Pin_BYP                    (* (reg8 *) LED3Pin__BYP)
/* Port wide control signals */                                                   
#define LED3Pin_CTL                    (* (reg8 *) LED3Pin__CTL)
/* Drive Modes */
#define LED3Pin_DM0                    (* (reg8 *) LED3Pin__DM0) 
#define LED3Pin_DM1                    (* (reg8 *) LED3Pin__DM1)
#define LED3Pin_DM2                    (* (reg8 *) LED3Pin__DM2) 
/* Input Buffer Disable Override */
#define LED3Pin_INP_DIS                (* (reg8 *) LED3Pin__INP_DIS)
/* LCD Common or Segment Drive */
#define LED3Pin_LCD_COM_SEG            (* (reg8 *) LED3Pin__LCD_COM_SEG)
/* Enable Segment LCD */
#define LED3Pin_LCD_EN                 (* (reg8 *) LED3Pin__LCD_EN)
/* Slew Rate Control */
#define LED3Pin_SLW                    (* (reg8 *) LED3Pin__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LED3Pin_PRTDSI__CAPS_SEL       (* (reg8 *) LED3Pin__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LED3Pin_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LED3Pin__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LED3Pin_PRTDSI__OE_SEL0        (* (reg8 *) LED3Pin__PRTDSI__OE_SEL0) 
#define LED3Pin_PRTDSI__OE_SEL1        (* (reg8 *) LED3Pin__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LED3Pin_PRTDSI__OUT_SEL0       (* (reg8 *) LED3Pin__PRTDSI__OUT_SEL0) 
#define LED3Pin_PRTDSI__OUT_SEL1       (* (reg8 *) LED3Pin__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LED3Pin_PRTDSI__SYNC_OUT       (* (reg8 *) LED3Pin__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(LED3Pin__SIO_CFG)
    #define LED3Pin_SIO_HYST_EN        (* (reg8 *) LED3Pin__SIO_HYST_EN)
    #define LED3Pin_SIO_REG_HIFREQ     (* (reg8 *) LED3Pin__SIO_REG_HIFREQ)
    #define LED3Pin_SIO_CFG            (* (reg8 *) LED3Pin__SIO_CFG)
    #define LED3Pin_SIO_DIFF           (* (reg8 *) LED3Pin__SIO_DIFF)
#endif /* (LED3Pin__SIO_CFG) */

/* Interrupt Registers */
#if defined(LED3Pin__INTSTAT)
    #define LED3Pin_INTSTAT            (* (reg8 *) LED3Pin__INTSTAT)
    #define LED3Pin_SNAP               (* (reg8 *) LED3Pin__SNAP)
    
	#define LED3Pin_0_INTTYPE_REG 		(* (reg8 *) LED3Pin__0__INTTYPE)
#endif /* (LED3Pin__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LED3Pin_H */


/* [] END OF FILE */
