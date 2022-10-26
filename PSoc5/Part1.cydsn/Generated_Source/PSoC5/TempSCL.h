/*******************************************************************************
* File Name: TempSCL.h  
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

#if !defined(CY_PINS_TempSCL_H) /* Pins TempSCL_H */
#define CY_PINS_TempSCL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "TempSCL_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 TempSCL__PORT == 15 && ((TempSCL__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    TempSCL_Write(uint8 value);
void    TempSCL_SetDriveMode(uint8 mode);
uint8   TempSCL_ReadDataReg(void);
uint8   TempSCL_Read(void);
void    TempSCL_SetInterruptMode(uint16 position, uint16 mode);
uint8   TempSCL_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the TempSCL_SetDriveMode() function.
     *  @{
     */
        #define TempSCL_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define TempSCL_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define TempSCL_DM_RES_UP          PIN_DM_RES_UP
        #define TempSCL_DM_RES_DWN         PIN_DM_RES_DWN
        #define TempSCL_DM_OD_LO           PIN_DM_OD_LO
        #define TempSCL_DM_OD_HI           PIN_DM_OD_HI
        #define TempSCL_DM_STRONG          PIN_DM_STRONG
        #define TempSCL_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define TempSCL_MASK               TempSCL__MASK
#define TempSCL_SHIFT              TempSCL__SHIFT
#define TempSCL_WIDTH              1u

/* Interrupt constants */
#if defined(TempSCL__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in TempSCL_SetInterruptMode() function.
     *  @{
     */
        #define TempSCL_INTR_NONE      (uint16)(0x0000u)
        #define TempSCL_INTR_RISING    (uint16)(0x0001u)
        #define TempSCL_INTR_FALLING   (uint16)(0x0002u)
        #define TempSCL_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define TempSCL_INTR_MASK      (0x01u) 
#endif /* (TempSCL__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define TempSCL_PS                     (* (reg8 *) TempSCL__PS)
/* Data Register */
#define TempSCL_DR                     (* (reg8 *) TempSCL__DR)
/* Port Number */
#define TempSCL_PRT_NUM                (* (reg8 *) TempSCL__PRT) 
/* Connect to Analog Globals */                                                  
#define TempSCL_AG                     (* (reg8 *) TempSCL__AG)                       
/* Analog MUX bux enable */
#define TempSCL_AMUX                   (* (reg8 *) TempSCL__AMUX) 
/* Bidirectional Enable */                                                        
#define TempSCL_BIE                    (* (reg8 *) TempSCL__BIE)
/* Bit-mask for Aliased Register Access */
#define TempSCL_BIT_MASK               (* (reg8 *) TempSCL__BIT_MASK)
/* Bypass Enable */
#define TempSCL_BYP                    (* (reg8 *) TempSCL__BYP)
/* Port wide control signals */                                                   
#define TempSCL_CTL                    (* (reg8 *) TempSCL__CTL)
/* Drive Modes */
#define TempSCL_DM0                    (* (reg8 *) TempSCL__DM0) 
#define TempSCL_DM1                    (* (reg8 *) TempSCL__DM1)
#define TempSCL_DM2                    (* (reg8 *) TempSCL__DM2) 
/* Input Buffer Disable Override */
#define TempSCL_INP_DIS                (* (reg8 *) TempSCL__INP_DIS)
/* LCD Common or Segment Drive */
#define TempSCL_LCD_COM_SEG            (* (reg8 *) TempSCL__LCD_COM_SEG)
/* Enable Segment LCD */
#define TempSCL_LCD_EN                 (* (reg8 *) TempSCL__LCD_EN)
/* Slew Rate Control */
#define TempSCL_SLW                    (* (reg8 *) TempSCL__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define TempSCL_PRTDSI__CAPS_SEL       (* (reg8 *) TempSCL__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define TempSCL_PRTDSI__DBL_SYNC_IN    (* (reg8 *) TempSCL__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define TempSCL_PRTDSI__OE_SEL0        (* (reg8 *) TempSCL__PRTDSI__OE_SEL0) 
#define TempSCL_PRTDSI__OE_SEL1        (* (reg8 *) TempSCL__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define TempSCL_PRTDSI__OUT_SEL0       (* (reg8 *) TempSCL__PRTDSI__OUT_SEL0) 
#define TempSCL_PRTDSI__OUT_SEL1       (* (reg8 *) TempSCL__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define TempSCL_PRTDSI__SYNC_OUT       (* (reg8 *) TempSCL__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(TempSCL__SIO_CFG)
    #define TempSCL_SIO_HYST_EN        (* (reg8 *) TempSCL__SIO_HYST_EN)
    #define TempSCL_SIO_REG_HIFREQ     (* (reg8 *) TempSCL__SIO_REG_HIFREQ)
    #define TempSCL_SIO_CFG            (* (reg8 *) TempSCL__SIO_CFG)
    #define TempSCL_SIO_DIFF           (* (reg8 *) TempSCL__SIO_DIFF)
#endif /* (TempSCL__SIO_CFG) */

/* Interrupt Registers */
#if defined(TempSCL__INTSTAT)
    #define TempSCL_INTSTAT            (* (reg8 *) TempSCL__INTSTAT)
    #define TempSCL_SNAP               (* (reg8 *) TempSCL__SNAP)
    
	#define TempSCL_0_INTTYPE_REG 		(* (reg8 *) TempSCL__0__INTTYPE)
#endif /* (TempSCL__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_TempSCL_H */


/* [] END OF FILE */
