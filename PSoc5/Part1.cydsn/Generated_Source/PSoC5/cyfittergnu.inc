/*******************************************************************************
* File Name: cyfittergnu.inc
* 
* PSoC Creator  4.4
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2020 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

.ifndef INCLUDED_CYFITTERGNU_INC
.set INCLUDED_CYFITTERGNU_INC, 1
.include "cydevicegnu.inc"
.include "cydevicegnu_trm.inc"

/* I2CTemp */
.set I2CTemp_I2C_FF__ADR, CYREG_I2C_ADR
.set I2CTemp_I2C_FF__CFG, CYREG_I2C_CFG
.set I2CTemp_I2C_FF__CLK_DIV1, CYREG_I2C_CLK_DIV1
.set I2CTemp_I2C_FF__CLK_DIV2, CYREG_I2C_CLK_DIV2
.set I2CTemp_I2C_FF__CSR, CYREG_I2C_CSR
.set I2CTemp_I2C_FF__D, CYREG_I2C_D
.set I2CTemp_I2C_FF__MCSR, CYREG_I2C_MCSR
.set I2CTemp_I2C_FF__PM_ACT_CFG, CYREG_PM_ACT_CFG5
.set I2CTemp_I2C_FF__PM_ACT_MSK, 0x04
.set I2CTemp_I2C_FF__PM_STBY_CFG, CYREG_PM_STBY_CFG5
.set I2CTemp_I2C_FF__PM_STBY_MSK, 0x04
.set I2CTemp_I2C_FF__TMOUT_CFG0, CYREG_I2C_TMOUT_CFG0
.set I2CTemp_I2C_FF__TMOUT_CFG1, CYREG_I2C_TMOUT_CFG1
.set I2CTemp_I2C_FF__TMOUT_CSR, CYREG_I2C_TMOUT_CSR
.set I2CTemp_I2C_FF__TMOUT_SR, CYREG_I2C_TMOUT_SR
.set I2CTemp_I2C_FF__XCFG, CYREG_I2C_XCFG
.set I2CTemp_I2C_IRQ__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set I2CTemp_I2C_IRQ__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set I2CTemp_I2C_IRQ__INTC_MASK, 0x8000
.set I2CTemp_I2C_IRQ__INTC_NUMBER, 15
.set I2CTemp_I2C_IRQ__INTC_PRIOR_NUM, 7
.set I2CTemp_I2C_IRQ__INTC_PRIOR_REG, CYREG_NVIC_PRI_15
.set I2CTemp_I2C_IRQ__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set I2CTemp_I2C_IRQ__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* LED1Pin */
.set LED1Pin__0__INTTYPE, CYREG_PICU0_INTTYPE3
.set LED1Pin__0__MASK, 0x08
.set LED1Pin__0__PC, CYREG_PRT0_PC3
.set LED1Pin__0__PORT, 0
.set LED1Pin__0__SHIFT, 3
.set LED1Pin__AG, CYREG_PRT0_AG
.set LED1Pin__AMUX, CYREG_PRT0_AMUX
.set LED1Pin__BIE, CYREG_PRT0_BIE
.set LED1Pin__BIT_MASK, CYREG_PRT0_BIT_MASK
.set LED1Pin__BYP, CYREG_PRT0_BYP
.set LED1Pin__CTL, CYREG_PRT0_CTL
.set LED1Pin__DM0, CYREG_PRT0_DM0
.set LED1Pin__DM1, CYREG_PRT0_DM1
.set LED1Pin__DM2, CYREG_PRT0_DM2
.set LED1Pin__DR, CYREG_PRT0_DR
.set LED1Pin__INP_DIS, CYREG_PRT0_INP_DIS
.set LED1Pin__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU0_BASE
.set LED1Pin__LCD_COM_SEG, CYREG_PRT0_LCD_COM_SEG
.set LED1Pin__LCD_EN, CYREG_PRT0_LCD_EN
.set LED1Pin__MASK, 0x08
.set LED1Pin__PORT, 0
.set LED1Pin__PRT, CYREG_PRT0_PRT
.set LED1Pin__PRTDSI__CAPS_SEL, CYREG_PRT0_CAPS_SEL
.set LED1Pin__PRTDSI__DBL_SYNC_IN, CYREG_PRT0_DBL_SYNC_IN
.set LED1Pin__PRTDSI__OE_SEL0, CYREG_PRT0_OE_SEL0
.set LED1Pin__PRTDSI__OE_SEL1, CYREG_PRT0_OE_SEL1
.set LED1Pin__PRTDSI__OUT_SEL0, CYREG_PRT0_OUT_SEL0
.set LED1Pin__PRTDSI__OUT_SEL1, CYREG_PRT0_OUT_SEL1
.set LED1Pin__PRTDSI__SYNC_OUT, CYREG_PRT0_SYNC_OUT
.set LED1Pin__PS, CYREG_PRT0_PS
.set LED1Pin__SHIFT, 3
.set LED1Pin__SLW, CYREG_PRT0_SLW

/* LED2Pin */
.set LED2Pin__0__INTTYPE, CYREG_PICU0_INTTYPE2
.set LED2Pin__0__MASK, 0x04
.set LED2Pin__0__PC, CYREG_PRT0_PC2
.set LED2Pin__0__PORT, 0
.set LED2Pin__0__SHIFT, 2
.set LED2Pin__AG, CYREG_PRT0_AG
.set LED2Pin__AMUX, CYREG_PRT0_AMUX
.set LED2Pin__BIE, CYREG_PRT0_BIE
.set LED2Pin__BIT_MASK, CYREG_PRT0_BIT_MASK
.set LED2Pin__BYP, CYREG_PRT0_BYP
.set LED2Pin__CTL, CYREG_PRT0_CTL
.set LED2Pin__DM0, CYREG_PRT0_DM0
.set LED2Pin__DM1, CYREG_PRT0_DM1
.set LED2Pin__DM2, CYREG_PRT0_DM2
.set LED2Pin__DR, CYREG_PRT0_DR
.set LED2Pin__INP_DIS, CYREG_PRT0_INP_DIS
.set LED2Pin__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU0_BASE
.set LED2Pin__LCD_COM_SEG, CYREG_PRT0_LCD_COM_SEG
.set LED2Pin__LCD_EN, CYREG_PRT0_LCD_EN
.set LED2Pin__MASK, 0x04
.set LED2Pin__PORT, 0
.set LED2Pin__PRT, CYREG_PRT0_PRT
.set LED2Pin__PRTDSI__CAPS_SEL, CYREG_PRT0_CAPS_SEL
.set LED2Pin__PRTDSI__DBL_SYNC_IN, CYREG_PRT0_DBL_SYNC_IN
.set LED2Pin__PRTDSI__OE_SEL0, CYREG_PRT0_OE_SEL0
.set LED2Pin__PRTDSI__OE_SEL1, CYREG_PRT0_OE_SEL1
.set LED2Pin__PRTDSI__OUT_SEL0, CYREG_PRT0_OUT_SEL0
.set LED2Pin__PRTDSI__OUT_SEL1, CYREG_PRT0_OUT_SEL1
.set LED2Pin__PRTDSI__SYNC_OUT, CYREG_PRT0_SYNC_OUT
.set LED2Pin__PS, CYREG_PRT0_PS
.set LED2Pin__SHIFT, 2
.set LED2Pin__SLW, CYREG_PRT0_SLW

/* LED3Pin */
.set LED3Pin__0__INTTYPE, CYREG_PICU0_INTTYPE1
.set LED3Pin__0__MASK, 0x02
.set LED3Pin__0__PC, CYREG_PRT0_PC1
.set LED3Pin__0__PORT, 0
.set LED3Pin__0__SHIFT, 1
.set LED3Pin__AG, CYREG_PRT0_AG
.set LED3Pin__AMUX, CYREG_PRT0_AMUX
.set LED3Pin__BIE, CYREG_PRT0_BIE
.set LED3Pin__BIT_MASK, CYREG_PRT0_BIT_MASK
.set LED3Pin__BYP, CYREG_PRT0_BYP
.set LED3Pin__CTL, CYREG_PRT0_CTL
.set LED3Pin__DM0, CYREG_PRT0_DM0
.set LED3Pin__DM1, CYREG_PRT0_DM1
.set LED3Pin__DM2, CYREG_PRT0_DM2
.set LED3Pin__DR, CYREG_PRT0_DR
.set LED3Pin__INP_DIS, CYREG_PRT0_INP_DIS
.set LED3Pin__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU0_BASE
.set LED3Pin__LCD_COM_SEG, CYREG_PRT0_LCD_COM_SEG
.set LED3Pin__LCD_EN, CYREG_PRT0_LCD_EN
.set LED3Pin__MASK, 0x02
.set LED3Pin__PORT, 0
.set LED3Pin__PRT, CYREG_PRT0_PRT
.set LED3Pin__PRTDSI__CAPS_SEL, CYREG_PRT0_CAPS_SEL
.set LED3Pin__PRTDSI__DBL_SYNC_IN, CYREG_PRT0_DBL_SYNC_IN
.set LED3Pin__PRTDSI__OE_SEL0, CYREG_PRT0_OE_SEL0
.set LED3Pin__PRTDSI__OE_SEL1, CYREG_PRT0_OE_SEL1
.set LED3Pin__PRTDSI__OUT_SEL0, CYREG_PRT0_OUT_SEL0
.set LED3Pin__PRTDSI__OUT_SEL1, CYREG_PRT0_OUT_SEL1
.set LED3Pin__PRTDSI__SYNC_OUT, CYREG_PRT0_SYNC_OUT
.set LED3Pin__PS, CYREG_PRT0_PS
.set LED3Pin__SHIFT, 1
.set LED3Pin__SLW, CYREG_PRT0_SLW

/* LED4Pin */
.set LED4Pin__0__INTTYPE, CYREG_PICU0_INTTYPE0
.set LED4Pin__0__MASK, 0x01
.set LED4Pin__0__PC, CYREG_PRT0_PC0
.set LED4Pin__0__PORT, 0
.set LED4Pin__0__SHIFT, 0
.set LED4Pin__AG, CYREG_PRT0_AG
.set LED4Pin__AMUX, CYREG_PRT0_AMUX
.set LED4Pin__BIE, CYREG_PRT0_BIE
.set LED4Pin__BIT_MASK, CYREG_PRT0_BIT_MASK
.set LED4Pin__BYP, CYREG_PRT0_BYP
.set LED4Pin__CTL, CYREG_PRT0_CTL
.set LED4Pin__DM0, CYREG_PRT0_DM0
.set LED4Pin__DM1, CYREG_PRT0_DM1
.set LED4Pin__DM2, CYREG_PRT0_DM2
.set LED4Pin__DR, CYREG_PRT0_DR
.set LED4Pin__INP_DIS, CYREG_PRT0_INP_DIS
.set LED4Pin__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU0_BASE
.set LED4Pin__LCD_COM_SEG, CYREG_PRT0_LCD_COM_SEG
.set LED4Pin__LCD_EN, CYREG_PRT0_LCD_EN
.set LED4Pin__MASK, 0x01
.set LED4Pin__PORT, 0
.set LED4Pin__PRT, CYREG_PRT0_PRT
.set LED4Pin__PRTDSI__CAPS_SEL, CYREG_PRT0_CAPS_SEL
.set LED4Pin__PRTDSI__DBL_SYNC_IN, CYREG_PRT0_DBL_SYNC_IN
.set LED4Pin__PRTDSI__OE_SEL0, CYREG_PRT0_OE_SEL0
.set LED4Pin__PRTDSI__OE_SEL1, CYREG_PRT0_OE_SEL1
.set LED4Pin__PRTDSI__OUT_SEL0, CYREG_PRT0_OUT_SEL0
.set LED4Pin__PRTDSI__OUT_SEL1, CYREG_PRT0_OUT_SEL1
.set LED4Pin__PRTDSI__SYNC_OUT, CYREG_PRT0_SYNC_OUT
.set LED4Pin__PS, CYREG_PRT0_PS
.set LED4Pin__SHIFT, 0
.set LED4Pin__SLW, CYREG_PRT0_SLW

/* TempSCL */
.set TempSCL__0__INTTYPE, CYREG_PICU3_INTTYPE0
.set TempSCL__0__MASK, 0x01
.set TempSCL__0__PC, CYREG_PRT3_PC0
.set TempSCL__0__PORT, 3
.set TempSCL__0__SHIFT, 0
.set TempSCL__AG, CYREG_PRT3_AG
.set TempSCL__AMUX, CYREG_PRT3_AMUX
.set TempSCL__BIE, CYREG_PRT3_BIE
.set TempSCL__BIT_MASK, CYREG_PRT3_BIT_MASK
.set TempSCL__BYP, CYREG_PRT3_BYP
.set TempSCL__CTL, CYREG_PRT3_CTL
.set TempSCL__DM0, CYREG_PRT3_DM0
.set TempSCL__DM1, CYREG_PRT3_DM1
.set TempSCL__DM2, CYREG_PRT3_DM2
.set TempSCL__DR, CYREG_PRT3_DR
.set TempSCL__INP_DIS, CYREG_PRT3_INP_DIS
.set TempSCL__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU3_BASE
.set TempSCL__LCD_COM_SEG, CYREG_PRT3_LCD_COM_SEG
.set TempSCL__LCD_EN, CYREG_PRT3_LCD_EN
.set TempSCL__MASK, 0x01
.set TempSCL__PORT, 3
.set TempSCL__PRT, CYREG_PRT3_PRT
.set TempSCL__PRTDSI__CAPS_SEL, CYREG_PRT3_CAPS_SEL
.set TempSCL__PRTDSI__DBL_SYNC_IN, CYREG_PRT3_DBL_SYNC_IN
.set TempSCL__PRTDSI__OE_SEL0, CYREG_PRT3_OE_SEL0
.set TempSCL__PRTDSI__OE_SEL1, CYREG_PRT3_OE_SEL1
.set TempSCL__PRTDSI__OUT_SEL0, CYREG_PRT3_OUT_SEL0
.set TempSCL__PRTDSI__OUT_SEL1, CYREG_PRT3_OUT_SEL1
.set TempSCL__PRTDSI__SYNC_OUT, CYREG_PRT3_SYNC_OUT
.set TempSCL__PS, CYREG_PRT3_PS
.set TempSCL__SHIFT, 0
.set TempSCL__SLW, CYREG_PRT3_SLW

/* TempSDA */
.set TempSDA__0__INTTYPE, CYREG_PICU3_INTTYPE1
.set TempSDA__0__MASK, 0x02
.set TempSDA__0__PC, CYREG_PRT3_PC1
.set TempSDA__0__PORT, 3
.set TempSDA__0__SHIFT, 1
.set TempSDA__AG, CYREG_PRT3_AG
.set TempSDA__AMUX, CYREG_PRT3_AMUX
.set TempSDA__BIE, CYREG_PRT3_BIE
.set TempSDA__BIT_MASK, CYREG_PRT3_BIT_MASK
.set TempSDA__BYP, CYREG_PRT3_BYP
.set TempSDA__CTL, CYREG_PRT3_CTL
.set TempSDA__DM0, CYREG_PRT3_DM0
.set TempSDA__DM1, CYREG_PRT3_DM1
.set TempSDA__DM2, CYREG_PRT3_DM2
.set TempSDA__DR, CYREG_PRT3_DR
.set TempSDA__INP_DIS, CYREG_PRT3_INP_DIS
.set TempSDA__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU3_BASE
.set TempSDA__LCD_COM_SEG, CYREG_PRT3_LCD_COM_SEG
.set TempSDA__LCD_EN, CYREG_PRT3_LCD_EN
.set TempSDA__MASK, 0x02
.set TempSDA__PORT, 3
.set TempSDA__PRT, CYREG_PRT3_PRT
.set TempSDA__PRTDSI__CAPS_SEL, CYREG_PRT3_CAPS_SEL
.set TempSDA__PRTDSI__DBL_SYNC_IN, CYREG_PRT3_DBL_SYNC_IN
.set TempSDA__PRTDSI__OE_SEL0, CYREG_PRT3_OE_SEL0
.set TempSDA__PRTDSI__OE_SEL1, CYREG_PRT3_OE_SEL1
.set TempSDA__PRTDSI__OUT_SEL0, CYREG_PRT3_OUT_SEL0
.set TempSDA__PRTDSI__OUT_SEL1, CYREG_PRT3_OUT_SEL1
.set TempSDA__PRTDSI__SYNC_OUT, CYREG_PRT3_SYNC_OUT
.set TempSDA__PS, CYREG_PRT3_PS
.set TempSDA__SHIFT, 1
.set TempSDA__SLW, CYREG_PRT3_SLW

/* Miscellaneous */
.set BCLK__BUS_CLK__HZ, 50000000
.set BCLK__BUS_CLK__KHZ, 50000
.set BCLK__BUS_CLK__MHZ, 50
.set CYDEV_CHIP_DIE_LEOPARD, 1
.set CYDEV_CHIP_DIE_PSOC4A, 26
.set CYDEV_CHIP_DIE_PSOC5LP, 2
.set CYDEV_CHIP_DIE_PSOC5TM, 3
.set CYDEV_CHIP_DIE_TMA4, 4
.set CYDEV_CHIP_DIE_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_FM0P, 5
.set CYDEV_CHIP_FAMILY_FM3, 6
.set CYDEV_CHIP_FAMILY_FM4, 7
.set CYDEV_CHIP_FAMILY_PSOC3, 1
.set CYDEV_CHIP_FAMILY_PSOC4, 2
.set CYDEV_CHIP_FAMILY_PSOC5, 3
.set CYDEV_CHIP_FAMILY_PSOC6, 4
.set CYDEV_CHIP_FAMILY_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_USED, CYDEV_CHIP_FAMILY_PSOC5
.set CYDEV_CHIP_JTAG_ID, 0x2E123069
.set CYDEV_CHIP_MEMBER_3A, 1
.set CYDEV_CHIP_MEMBER_4A, 26
.set CYDEV_CHIP_MEMBER_4AA, 25
.set CYDEV_CHIP_MEMBER_4AB, 30
.set CYDEV_CHIP_MEMBER_4AC, 14
.set CYDEV_CHIP_MEMBER_4AD, 15
.set CYDEV_CHIP_MEMBER_4AE, 16
.set CYDEV_CHIP_MEMBER_4D, 20
.set CYDEV_CHIP_MEMBER_4E, 6
.set CYDEV_CHIP_MEMBER_4F, 27
.set CYDEV_CHIP_MEMBER_4G, 4
.set CYDEV_CHIP_MEMBER_4H, 24
.set CYDEV_CHIP_MEMBER_4I, 32
.set CYDEV_CHIP_MEMBER_4J, 21
.set CYDEV_CHIP_MEMBER_4K, 22
.set CYDEV_CHIP_MEMBER_4L, 31
.set CYDEV_CHIP_MEMBER_4M, 29
.set CYDEV_CHIP_MEMBER_4N, 11
.set CYDEV_CHIP_MEMBER_4O, 8
.set CYDEV_CHIP_MEMBER_4P, 28
.set CYDEV_CHIP_MEMBER_4Q, 17
.set CYDEV_CHIP_MEMBER_4R, 9
.set CYDEV_CHIP_MEMBER_4S, 12
.set CYDEV_CHIP_MEMBER_4T, 10
.set CYDEV_CHIP_MEMBER_4U, 5
.set CYDEV_CHIP_MEMBER_4V, 23
.set CYDEV_CHIP_MEMBER_4W, 13
.set CYDEV_CHIP_MEMBER_4X, 7
.set CYDEV_CHIP_MEMBER_4Y, 18
.set CYDEV_CHIP_MEMBER_4Z, 19
.set CYDEV_CHIP_MEMBER_5A, 3
.set CYDEV_CHIP_MEMBER_5B, 2
.set CYDEV_CHIP_MEMBER_6A, 33
.set CYDEV_CHIP_MEMBER_FM3, 37
.set CYDEV_CHIP_MEMBER_FM4, 38
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1, 34
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2, 35
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3, 36
.set CYDEV_CHIP_MEMBER_UNKNOWN, 0
.set CYDEV_CHIP_MEMBER_USED, CYDEV_CHIP_MEMBER_5B
.set CYDEV_CHIP_DIE_EXPECT, CYDEV_CHIP_MEMBER_USED
.set CYDEV_CHIP_DIE_ACTUAL, CYDEV_CHIP_DIE_EXPECT
.set CYDEV_CHIP_REV_LEOPARD_ES1, 0
.set CYDEV_CHIP_REV_LEOPARD_ES2, 1
.set CYDEV_CHIP_REV_LEOPARD_ES3, 3
.set CYDEV_CHIP_REV_LEOPARD_PRODUCTION, 3
.set CYDEV_CHIP_REV_PSOC4A_ES0, 17
.set CYDEV_CHIP_REV_PSOC4A_PRODUCTION, 17
.set CYDEV_CHIP_REV_PSOC5LP_ES0, 0
.set CYDEV_CHIP_REV_PSOC5LP_PRODUCTION, 0
.set CYDEV_CHIP_REV_PSOC5TM_ES0, 0
.set CYDEV_CHIP_REV_PSOC5TM_ES1, 1
.set CYDEV_CHIP_REV_PSOC5TM_PRODUCTION, 1
.set CYDEV_CHIP_REV_TMA4_ES, 17
.set CYDEV_CHIP_REV_TMA4_ES2, 33
.set CYDEV_CHIP_REV_TMA4_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_3A_ES1, 0
.set CYDEV_CHIP_REVISION_3A_ES2, 1
.set CYDEV_CHIP_REVISION_3A_ES3, 3
.set CYDEV_CHIP_REVISION_3A_PRODUCTION, 3
.set CYDEV_CHIP_REVISION_4A_ES0, 17
.set CYDEV_CHIP_REVISION_4A_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4AA_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4AB_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4AC_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4AD_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4AE_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4D_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD, 0
.set CYDEV_CHIP_REVISION_4E_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION_256K, 0
.set CYDEV_CHIP_REVISION_4G_ES, 17
.set CYDEV_CHIP_REVISION_4G_ES2, 33
.set CYDEV_CHIP_REVISION_4G_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4H_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4I_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4J_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4K_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4L_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4M_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4N_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4O_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4P_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4Q_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4R_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4S_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4T_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4U_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4V_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4W_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4X_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4Y_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4Z_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_5A_ES0, 0
.set CYDEV_CHIP_REVISION_5A_ES1, 1
.set CYDEV_CHIP_REVISION_5A_PRODUCTION, 1
.set CYDEV_CHIP_REVISION_5B_ES0, 0
.set CYDEV_CHIP_REVISION_5B_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_6A_ES, 17
.set CYDEV_CHIP_REVISION_6A_NO_UDB, 33
.set CYDEV_CHIP_REVISION_6A_PRODUCTION, 33
.set CYDEV_CHIP_REVISION_FM3_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_FM4_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_USED, CYDEV_CHIP_REVISION_5B_PRODUCTION
.set CYDEV_CHIP_REV_EXPECT, CYDEV_CHIP_REVISION_USED
.set CYDEV_CONFIG_FASTBOOT_ENABLED, 1
.set CYDEV_CONFIG_UNUSED_IO_AllowButWarn, 0
.set CYDEV_CONFIG_UNUSED_IO, CYDEV_CONFIG_UNUSED_IO_AllowButWarn
.set CYDEV_CONFIG_UNUSED_IO_AllowWithInfo, 1
.set CYDEV_CONFIG_UNUSED_IO_Disallowed, 2
.set CYDEV_CONFIGURATION_COMPRESSED, 1
.set CYDEV_CONFIGURATION_DMA, 0
.set CYDEV_CONFIGURATION_ECC, 1
.set CYDEV_CONFIGURATION_IMOENABLED, CYDEV_CONFIG_FASTBOOT_ENABLED
.set CYDEV_CONFIGURATION_MODE_COMPRESSED, 0
.set CYDEV_CONFIGURATION_MODE, CYDEV_CONFIGURATION_MODE_COMPRESSED
.set CYDEV_CONFIGURATION_MODE_DMA, 2
.set CYDEV_CONFIGURATION_MODE_UNCOMPRESSED, 1
.set CYDEV_DEBUG_ENABLE_MASK, 0x20
.set CYDEV_DEBUG_ENABLE_REGISTER, CYREG_MLOGIC_DEBUG
.set CYDEV_DEBUGGING_DPS_Disable, 3
.set CYDEV_DEBUGGING_DPS_JTAG_4, 1
.set CYDEV_DEBUGGING_DPS_JTAG_5, 0
.set CYDEV_DEBUGGING_DPS_SWD, 2
.set CYDEV_DEBUGGING_DPS_SWD_SWV, 6
.set CYDEV_DEBUGGING_DPS, CYDEV_DEBUGGING_DPS_SWD_SWV
.set CYDEV_DEBUGGING_ENABLE, 1
.set CYDEV_DEBUGGING_XRES, 0
.set CYDEV_DMA_CHANNELS_AVAILABLE, 24
.set CYDEV_ECC_ENABLE, 0
.set CYDEV_HEAP_SIZE, 0x80
.set CYDEV_INSTRUCT_CACHE_ENABLED, 1
.set CYDEV_INTR_RISING, 0x00008000
.set CYDEV_IS_EXPORTING_CODE, 0
.set CYDEV_IS_IMPORTING_CODE, 0
.set CYDEV_PROJ_TYPE, 0
.set CYDEV_PROJ_TYPE_BOOTLOADER, 1
.set CYDEV_PROJ_TYPE_LAUNCHER, 5
.set CYDEV_PROJ_TYPE_LOADABLE, 2
.set CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER, 4
.set CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER, 3
.set CYDEV_PROJ_TYPE_STANDARD, 0
.set CYDEV_PROTECTION_ENABLE, 0
.set CYDEV_STACK_SIZE, 0x0800
.set CYDEV_USE_BUNDLED_CMSIS, 1
.set CYDEV_VARIABLE_VDDA, 0
.set CYDEV_VDDA_MV, 5000
.set CYDEV_VDDD_MV, 5000
.set CYDEV_VDDIO0_MV, 5000
.set CYDEV_VDDIO1_MV, 5000
.set CYDEV_VDDIO2_MV, 5000
.set CYDEV_VDDIO3_MV, 5000
.set CYDEV_VIO0_MV, 5000
.set CYDEV_VIO1_MV, 5000
.set CYDEV_VIO2_MV, 5000
.set CYDEV_VIO3_MV, 5000
.set CYIPBLOCK_ARM_CM3_VERSION, 0
.set CYIPBLOCK_P3_ANAIF_VERSION, 0
.set CYIPBLOCK_P3_CAN_VERSION, 0
.set CYIPBLOCK_P3_CAPSENSE_VERSION, 0
.set CYIPBLOCK_P3_COMP_VERSION, 0
.set CYIPBLOCK_P3_DECIMATOR_VERSION, 0
.set CYIPBLOCK_P3_DFB_VERSION, 0
.set CYIPBLOCK_P3_DMA_VERSION, 0
.set CYIPBLOCK_P3_DRQ_VERSION, 0
.set CYIPBLOCK_P3_DSM_VERSION, 0
.set CYIPBLOCK_P3_EMIF_VERSION, 0
.set CYIPBLOCK_P3_I2C_VERSION, 0
.set CYIPBLOCK_P3_LCD_VERSION, 0
.set CYIPBLOCK_P3_LPF_VERSION, 0
.set CYIPBLOCK_P3_OPAMP_VERSION, 0
.set CYIPBLOCK_P3_PM_VERSION, 0
.set CYIPBLOCK_P3_SCCT_VERSION, 0
.set CYIPBLOCK_P3_TIMER_VERSION, 0
.set CYIPBLOCK_P3_USB_VERSION, 0
.set CYIPBLOCK_P3_VIDAC_VERSION, 0
.set CYIPBLOCK_P3_VREF_VERSION, 0
.set CYIPBLOCK_S8_GPIO_VERSION, 0
.set CYIPBLOCK_S8_IRQ_VERSION, 0
.set CYIPBLOCK_S8_SAR_VERSION, 0
.set CYIPBLOCK_S8_SIO_VERSION, 0
.set CYIPBLOCK_S8_UDB_VERSION, 0
.set DMA_CHANNELS_USED__MASK0, 0x00000000
.set CYDEV_BOOTLOADER_ENABLE, 0
.endif
