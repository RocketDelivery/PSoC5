/*******************************************************************************
* File Name: TempSDA.h  
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

#if !defined(CY_PINS_TempSDA_H) /* Pins TempSDA_H */
#define CY_PINS_TempSDA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "TempSDA_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 TempSDA__PORT == 15 && ((TempSDA__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    TempSDA_Write(uint8 value);
void    TempSDA_SetDriveMode(uint8 mode);
uint8   TempSDA_ReadDataReg(void);
uint8   TempSDA_Read(void);
void    TempSDA_SetInterruptMode(uint16 position, uint16 mode);
uint8   TempSDA_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the TempSDA_SetDriveMode() function.
     *  @{
     */
        #define TempSDA_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define TempSDA_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define TempSDA_DM_RES_UP          PIN_DM_RES_UP
        #define TempSDA_DM_RES_DWN         PIN_DM_RES_DWN
        #define TempSDA_DM_OD_LO           PIN_DM_OD_LO
        #define TempSDA_DM_OD_HI           PIN_DM_OD_HI
        #define TempSDA_DM_STRONG          PIN_DM_STRONG
        #define TempSDA_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define TempSDA_MASK               TempSDA__MASK
#define TempSDA_SHIFT              TempSDA__SHIFT
#define TempSDA_WIDTH              1u

/* Interrupt constants */
#if defined(TempSDA__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in TempSDA_SetInterruptMode() function.
     *  @{
     */
        #define TempSDA_INTR_NONE      (uint16)(0x0000u)
        #define TempSDA_INTR_RISING    (uint16)(0x0001u)
        #define TempSDA_INTR_FALLING   (uint16)(0x0002u)
        #define TempSDA_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define TempSDA_INTR_MASK      (0x01u) 
#endif /* (TempSDA__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define TempSDA_PS                     (* (reg8 *) TempSDA__PS)
/* Data Register */
#define TempSDA_DR                     (* (reg8 *) TempSDA__DR)
/* Port Number */
#define TempSDA_PRT_NUM                (* (reg8 *) TempSDA__PRT) 
/* Connect to Analog Globals */                                                  
#define TempSDA_AG                     (* (reg8 *) TempSDA__AG)                       
/* Analog MUX bux enable */
#define TempSDA_AMUX                   (* (reg8 *) TempSDA__AMUX) 
/* Bidirectional Enable */                                                        
#define TempSDA_BIE                    (* (reg8 *) TempSDA__BIE)
/* Bit-mask for Aliased Register Access */
#define TempSDA_BIT_MASK               (* (reg8 *) TempSDA__BIT_MASK)
/* Bypass Enable */
#define TempSDA_BYP                    (* (reg8 *) TempSDA__BYP)
/* Port wide control signals */                                                   
#define TempSDA_CTL                    (* (reg8 *) TempSDA__CTL)
/* Drive Modes */
#define TempSDA_DM0                    (* (reg8 *) TempSDA__DM0) 
#define TempSDA_DM1                    (* (reg8 *) TempSDA__DM1)
#define TempSDA_DM2                    (* (reg8 *) TempSDA__DM2) 
/* Input Buffer Disable Override */
#define TempSDA_INP_DIS                (* (reg8 *) TempSDA__INP_DIS)
/* LCD Common or Segment Drive */
#define TempSDA_LCD_COM_SEG            (* (reg8 *) TempSDA__LCD_COM_SEG)
/* Enable Segment LCD */
#define TempSDA_LCD_EN                 (* (reg8 *) TempSDA__LCD_EN)
/* Slew Rate Control */
#define TempSDA_SLW                    (* (reg8 *) TempSDA__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define TempSDA_PRTDSI__CAPS_SEL       (* (reg8 *) TempSDA__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define TempSDA_PRTDSI__DBL_SYNC_IN    (* (reg8 *) TempSDA__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define TempSDA_PRTDSI__OE_SEL0        (* (reg8 *) TempSDA__PRTDSI__OE_SEL0) 
#define TempSDA_PRTDSI__OE_SEL1        (* (reg8 *) TempSDA__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define TempSDA_PRTDSI__OUT_SEL0       (* (reg8 *) TempSDA__PRTDSI__OUT_SEL0) 
#define TempSDA_PRTDSI__OUT_SEL1       (* (reg8 *) TempSDA__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define TempSDA_PRTDSI__SYNC_OUT       (* (reg8 *) TempSDA__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(TempSDA__SIO_CFG)
    #define TempSDA_SIO_HYST_EN        (* (reg8 *) TempSDA__SIO_HYST_EN)
    #define TempSDA_SIO_REG_HIFREQ     (* (reg8 *) TempSDA__SIO_REG_HIFREQ)
    #define TempSDA_SIO_CFG            (* (reg8 *) TempSDA__SIO_CFG)
    #define TempSDA_SIO_DIFF           (* (reg8 *) TempSDA__SIO_DIFF)
#endif /* (TempSDA__SIO_CFG) */

/* Interrupt Registers */
#if defined(TempSDA__INTSTAT)
    #define TempSDA_INTSTAT            (* (reg8 *) TempSDA__INTSTAT)
    #define TempSDA_SNAP               (* (reg8 *) TempSDA__SNAP)
    
	#define TempSDA_0_INTTYPE_REG 		(* (reg8 *) TempSDA__0__INTTYPE)
#endif /* (TempSDA__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_TempSDA_H */


/* [] END OF FILE */
