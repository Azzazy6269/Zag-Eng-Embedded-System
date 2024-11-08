/* 
 * File:   CCP.h
 * Author: smart
 *
 * Created on 27 Aug, 2024, 03:34 ?
 */

#ifndef CCP1_H
#define	CCP1_H

/* -------------section : INCLUDES------------- */
#include "CCP1_CFG.h"
#include "../GPIO/hal_gpio.h"
#include "../Interrupt/Internal_interrupt.h"
#include "../mcal_std_types.h"

/* ---------------Section : MACRO Declerations---------------- */

/* CCP_mode_variant */
#define CCP_MODULE_DISABLE                  ((uint8)0x00)
#define CCP_CAPTURE_MODE_1_FALLING_EDGE     ((uint8)0x04)
#define CCP_CAPTURE_MODE_1_RISING_EDGE      ((uint8)0x05)
#define CCP_CAPTURE_MODE_4_RISING_EDGE      ((uint8)0x06)  
#define CCP_CAPTURE_MODE_16_RISING_EDGE     ((uint8)0x07)
#define CCP_COMPARE_MODE_SET_PIN_LOW        ((uint8)0x08)
#define CCP_COMPARE_MODE_SET_PIN_HIGH       ((uint8)0x09)
#define CCP_COMPARE_MODE_TOGGLE_ON_MATCH    ((uint8)0x02)
#define CCP_COMPARE_MODE_GEN_SW_INTERRUPT   ((uint8)0x0A)
#define CCP_COMPARE_MODE_GEN_EVENT          ((uint8)0x0B)
#define CCP_PWM_MODE                        ((uint8)0x0C)

/* CCP CAPTURE MODE STATE */
#define CCP_CAPTURE_NOT_READY               0x00
#define CCP_CAPTURE_READY                   0x01

/* CCP COMPARE MODE STATE */
#define CCP_COMPARE_NOT_READY               0x00
#define CCP_COMPARE_READY                   0x01

/**************************************************************************
 * NOTE : THESE MACROS DIFFER FROM PRESCALER AND POSTSCALER IN TIMER2.H *
 **************************************************************************/
/* Timer2_Prescaler_&_Postscaler_values */ 
#define CCP1_TIMER2_POSTSCALER_DIV_BY_1     1
#define CCP1_TIMER2_POSTSCALER_DIV_BY_2     2
#define CCP1_TIMER2_PPSTSCALER_DIV_BY_3     3
#define CCP1_TIMER2_POSTSCALER_DIV_BY_4     4
#define CCP1_TIMER2_POSTSCALER_DIV_BY_5     5
#define CCP1_TIMER2_POSTSCALER_DIV_BY_6     6
#define CCP1_TIMER2_POSTSCALER_DIV_BY_7     7
#define CCP1_TIMER2_POSTSCALER_DIV_BY_8     8
#define CCP1_TIMER2_POSTSCALER_DIV_BY_9     9
#define CCP1_TIMER2_POSTSCALER_DIV_BY_10    10
#define CCP1_TIMER2_POSTSCALER_DIV_BY_11    11
#define CCP1_TIMER2_POSTSCALER_DIV_BY_12    12
#define CCP1_TIMER2_POSTSCALER_DIV_BY_13    13
#define CCP1_TIMER2_POSTSCALER_DIV_BY_14    14
#define CCP1_TIMER2_POSTSCALER_DIV_BY_15    15
#define CCP1_TIMER2_POSTSCALER_DIV_BY_16    16


#define CCP1_TIMER2_PRESCALER_DIV_BY_1      1
#define CCP1_TIMER2_PRESCALER_DIV_BY_4      4
#define CCP1_TIMER2_PRESCALER_DIV_BY_16     16

/* ----------------Section : MACRO Functions Declerations--------------- */
#define CCP1_SET_MODE(_CONFIG)    (CCP1CONbits.CCP1M = _CONFIG)
#define CCP2_SET_MODE(_CONFIG)    (CCP2CONbits.CCP2M = _CONFIG)

/* --------------Section : Data Types Declerations-------------- */
typedef enum {
    CCP_CAPTURE_MODE_SELECTED = 0,
    CCP_COMPARE_MODE_SELECTED,
    CCP_PWM_MODE_SELECTED
}ccp_mode_t;
/*
 * @Summary  used to get two 8 bit values from 16bit also two 8 bit value are combine to get 16bit
 */
typedef union{
    struct{
       uint8 ccpr_low;   /* CCPR1 low register */
       uint8 ccpr_high;  /* CCPR1 high register */
    };
    struct{
        uint16 ccpr_16Bit; /* Read CCPR as a 16 Bit value */
    };
}CCP_REG_t;

typedef enum{
    CCP1_INST=0,
    CCP2_INST
}ccp_inst_t;

typedef enum{
    CCP1_CCP2_TIMER3=0, /* Timer3 is the capture/compare clock source for the CCP modules */
    CCP1_TIMER1_CCP2_TIMER3,/* Timer3 is the capture/compare clock source for CCP2;Timer1 is the capture/compare clock source for CCP1 */
    CCP1_CCP2_TIMER1 /* Timer1 is the capture/compare clock source for the CCP modules */
}ccp_capture_timer_t;

typedef struct{
    ccp_inst_t ccp_inst;
    ccp_mode_t CCP_mode ;
    uint8 CCP_mode_variant ;
    pin_config_t ccp_pin;
    ccp_capture_timer_t ccp_capture_timer;
#if CCP1_INTERRUPT_FEATURE_ENABLE == FEATURE_ENABLE
    void (* CCP1_InterruptHandler)(void);
    interrupt_priority_cfg CCP1_priority;

#endif
#if CCP2_INTERRUPT_FEATURE_ENABLE == FEATURE_ENABLE
    void (* CCP2_InterruptHandler)(void);
    interrupt_priority_cfg CCP2_priority;

#endif
#if CCP1_CFG_SELECTED_MODE == CCP_CFG_PWM_MODE_SELECTED
    uint32 PWM_Frequency;
    uint8 timer2_prescaler_value ;
    uint8 timer2_postscaler_value ;
#endif
}ccp_t;

/* -----------------Section : Function Declerations---------------- */
Std_ReturnType CCP_Init(const ccp_t * _ccp_obj);
Std_ReturnType CCP_DeInit(const ccp_t * _ccp_obj);

#if (CCP1_CFG_SELECTED_MODE == CCP_CFG_CAPTURE_MODE_SELECTED) || (CCP2_CFG_SELECTED_MODE == CCP_CFG_CAPTURE_MODE_SELECTED)
Std_ReturnType CCP_IsCapturedDataReady(const ccp_t * _ccp_obj,uint8 * _capture_status);
Std_ReturnType CCP_Capture_Mode_Read_Value(const ccp_t * _ccp_obj,uint8 * _capture_value);
#endif


#if (CCP1_CFG_SELECTED_MODE == CCP_CFG_COMPARE_MODE_SELECTED) || (CCP2_CFG_SELECTED_MODE == CCP_CFG_COMPARE_MODE_SELECTED)
Std_ReturnType CCP_IsCompareComplete(const ccp_t * _ccp_obj,uint8 * _compare_status);
Std_ReturnType CCP_Compare_Mode_Set_Value(const ccp_t * _ccp_obj,uint16 _compare_value); //This function must be used before CCP_Init() in application.c in compare mode 
#endif


#if (CCP1_CFG_SELECTED_MODE == CCP_CFG_PWM_MODE_SELECTED) ||(CCP2_CFG_SELECTED_MODE == CCP_CFG_PWM_MODE_SELECTED)
Std_ReturnType CCP_PWM_Set_Duty(const ccp_t * _ccp_obj,const uint8 _duty);
Std_ReturnType CCP_PWM_Start(const ccp_t * _ccp_obj);
Std_ReturnType CCP_PWM_Stop(const ccp_t * _ccp_obj);
#endif

#endif	/* CCP1_H */

