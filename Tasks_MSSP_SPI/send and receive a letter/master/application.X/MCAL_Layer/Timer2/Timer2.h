/* 
 * File:   Timer2.h
 * Author: smart
 *
 * Created on 23 Aug, 2024, 05:39 ?
 */

#ifndef TIMER2_H
#define	TIMER2_H


/* ------------------Section : Includes----------------- */
#include "../GPIO/hal_gpio.h"
#include "../Interrupt/Internal_interrupt.h"
#include "../mcal_std_types.h"

/* ------------Section : MACRO Declerations------------- */
#define TIMER2_POSTSCALER_DIV_BY_1     0
#define TIMER2_POSTSCALER_DIV_BY_2     1
#define TIMER2_PPSTSCALER_DIV_BY_3     2
#define TIMER2_POSTSCALER_DIV_BY_4     3
#define TIMER2_POSTSCALER_DIV_BY_5     4
#define TIMER2_POSTSCALER_DIV_BY_6     5
#define TIMER2_POSTSCALER_DIV_BY_7     6
#define TIMER2_POSTSCALER_DIV_BY_8     7
#define TIMER2_POSTSCALER_DIV_BY_9     8
#define TIMER2_POSTSCALER_DIV_BY_10    9
#define TIMER2_POSTSCALER_DIV_BY_11    10
#define TIMER2_POSTSCALER_DIV_BY_12    11
#define TIMER2_POSTSCALER_DIV_BY_13    12
#define TIMER2_POSTSCALER_DIV_BY_14    13
#define TIMER2_POSTSCALER_DIV_BY_15    14
#define TIMER2_POSTSCALER_DIV_BY_16    15


#define TIMER2_PRESCALER_DIV_BY_1      0
#define TIMER2_PRESCALER_DIV_BY_4      1
#define TIMER2_PRESCALER_DIV_BY_16     2

#undef _XTAL_FREQ
#define _XTAL_FREQ 4000000
/* -------------Section : MACRO Functions Declerations------------- */
/* Enable or Disable Timer2 Module */
#define TIMER2_MODULE_ENABLE()          (T2CONbits.TMR2ON = 1)
#define TIMER2_MODULE_DISABLE()         (T2CONbits.TMR2ON = 0)

#define TIMER_POSTSCALER_SELECT(_POSTSCALER_)  (T2CONbits.TOUTPS = _POSTSCALER_)
#define TIMER_PRESCALER_SELECT(_PRESCALER_)    (T2CONbits.T2CKPS = _PRESCALER_)


/* ------------Section : Data Types Declerations------------ */
typedef struct{
#if TIMER2_INTERRUPT_FEATURE_ENABLE   ==  FEATURE_ENABLE
    void (* TMR2_InterruptHandler)(void);
  #if INTERRUPT_PRIORITY_LEVELS_ENABLE  ==   FEATURE_ENABLE
        interrupt_priority_cfg priority ;
  #endif
#endif
        uint8 timer2_preload_value;
        uint8 timer2_prescaler_value: 2;
        uint8 timer2_postscaler_value: 4;
        uint8 timer2_reversed: 2;
}timer2_t;



/* ---------------Section : Function Declerations------------- */
Std_ReturnType Timer2_Init(const timer2_t * _timer);
Std_ReturnType Timer2_DeInit(const timer2_t * _timer);
Std_ReturnType Timer2_Write_value(const timer2_t * _timer,uint16 _value);
Std_ReturnType Timer2_Read_value(const timer2_t * _timer,uint16 *_value);



#endif	/* TIMER2_H */

