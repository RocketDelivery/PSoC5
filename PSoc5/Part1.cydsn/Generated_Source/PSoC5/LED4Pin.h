/*******************************************************************************
* File Name: LED4Pin.h  
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

#if !defined(CY_PINS_LED4Pin_H) /* Pins LED4Pin_H */
#define CY_PINS_LED4Pin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LED4Pin_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LED4Pin__PORT == 15 && ((LED4Pin__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    LED4Pin_Write(uint8 value);
void    LED4Pin_SetDriveMode(uint8 mode);
uint8   LED4Pin_ReadDataReg(void);
uint8   LED4Pin_Read(void);
void    LED4Pin_SetInterruptMode(uint16 position, uint16 mode);
uint8   LED4Pin_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the LED4Pin_SetDriveMode() function.
     *  @{
     */
        #define LED4Pin_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define LED4Pin_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define LED4Pin_DM_RES_UP          PIN_DM_RES_UP
        #define LED4Pin_DM_RES_DWN         PIN_DM_RES_DWN
        #define LED4Pin_DM_OD_LO           PIN_DM_OD_LO
        #define LED4Pin_DM_OD_HI           PIN_DM_OD_HI
        #define LED4Pin_DM_STRONG          PIN_DM_STRONG
        #define LED4Pin_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define LED4Pin_MASK               LED4Pin__MASK
#define LED4Pin_SHIFT              LED4Pin__SHIFT
#define LED4Pin_WIDTH              1u

/* Interrupt constants */
#if defined(LED4Pin__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LED4Pin_SetInterruptMode() function.
     *  @{
     */
        #define LED4Pin_INTR_NONE      (uint16)(0x0000u)
        #define LED4Pin_INTR_RISING    (uint16)(0x0001u)
        #define LED4Pin_INTR_FALLING   (uint16)(0x0002u)
        #define LED4Pin_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define LED4Pin_INTR_MASK      (0x01u) 
#endif /* (LED4Pin__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LED4Pin_PS                     (* (reg8 *) LED4Pin__PS)
/* Data Register */
#define LED4Pin_DR                     (* (reg8 *) LED4Pin__DR)
/* Port Number */
#define LED4Pin_PRT_NUM                (* (reg8 *) LED4Pin__PRT) 
/* Connect to Analog Globals */                                                  
#define LED4Pin_AG                     (* (reg8 *) LED4Pin__AG)                       
/* Analog MUX bux enable */
#define LED4Pin_AMUX                   (* (reg8 *) LED4Pin__AMUX) 
/* Bidirectional Enable */                                                        
#define LED4Pin_BIE                    (* (reg8 *) LED4Pin__BIE)
/* Bit-mask for Aliased Register Access */
#define LED4Pin_BIT_MASK               (* (reg8 *) LED4Pin__BIT_MASK)
/* Bypass Enable */
#define LED4Pin_BYP                    (* (reg8 *) LED4Pin__BYP)
/* Port wide control signals */                                                   
#define LED4Pin_CTL                    (* (reg8 *) LED4Pin__CTL)
/* Drive Modes */
#define LED4Pin_DM0                    (* (reg8 *) LED4Pin__DM0) 
#define LED4Pin_DM1                    (* (reg8 *) LED4Pin__DM1)
#define LED4Pin_DM2                    (* (reg8 *) LED4Pin__DM2) 
/* Input Buffer Disable Override */
#define LED4Pin_INP_DIS                (* (reg8 *) LED4Pin__INP_DIS)
/* LCD Common or Segment Drive */
#define LED4Pin_LCD_COM_SEG            (* (reg8 *) LED4Pin__LCD_COM_SEG)
/* Enable Segment LCD */
#define LED4Pin_LCD_EN                 (* (reg8 *) LED4Pin__LCD_EN)
/* Slew Rate Control */
#define LED4Pin_SLW                    (* (reg8 *) LED4Pin__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LED4Pin_PRTDSI__CAPS_SEL       (* (reg8 *) LED4Pin__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LED4Pin_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LED4Pin__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LED4Pin_PRTDSI__OE_SEL0        (* (reg8 *) LED4Pin__PRTDSI__OE_SEL0) 
#define LED4Pin_PRTDSI__OE_SEL1        (* (reg8 *) LED4Pin__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LED4Pin_PRTDSI__OUT_SEL0       (* (reg8 *) LED4Pin__PRTDSI__OUT_SEL0) 
#define LED4Pin_PRTDSI__OUT_SEL1       (* (reg8 *) LED4Pin__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LED4Pin_PRTDSI__SYNC_OUT       (* (reg8 *) LED4Pin__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(LED4Pin__SIO_CFG)
    #define LED4Pin_SIO_HYST_EN        (* (reg8 *) LED4Pin__SIO_HYST_EN)
    #define LED4Pin_SIO_REG_HIFREQ     (* (reg8 *) LED4Pin__SIO_REG_HIFREQ)
    #define LED4Pin_SIO_CFG            (* (reg8 *) LED4Pin__SIO_CFG)
    #define LED4Pin_SIO_DIFF           (* (reg8 *) LED4Pin__SIO_DIFF)
#endif /* (LED4Pin__SIO_CFG) */

/* Interrupt Registers */
#if defined(LED4Pin__INTSTAT)
    #define LED4Pin_INTSTAT            (* (reg8 *) LED4Pin__INTSTAT)
    #define LED4Pin_SNAP               (* (reg8 *) LED4Pin__SNAP)
    
	#define LED4Pin_0_INTTYPE_REG 		(* (reg8 *) LED4Pin__0__INTTYPE)
#endif /* (LED4Pin__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LED4Pin_H */


/* [] END OF FILE */
