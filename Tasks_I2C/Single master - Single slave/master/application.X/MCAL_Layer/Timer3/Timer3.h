/* 
 * File:   Timer3.h
 * Author: smart
 *
 * Created on 23 Aug, 2024, 10:55 ?
 */

#ifndef TIMER3_H
#define	TIMER3_H


/* ---------------Section : Includes----------------- */
#include "../GPIO/hal_gpio.h"
#include "../Interrupt/Internal_interrupt.h"
#include "../mcal_std_types.h"
/* ----------------Section : MACRO Declerations---------------- */
/* timer3_mode */
#define TIMER3_TIMER_MODE            0
#define TIMER3_COUNTER_MODE          1
/* timer3_counter_mode */
#define TIMER3_ASYNC_COUNTER_MODE    1
#define TIMER3_SYNC_COUNTER_MODE     0
/* prescaler_value */
#define TIMER3_PRESCALER_DIV_BY_1    0
#define TIMER3_PRESCALER_DIV_BY_2    1
#define TIMER3_PRESCALER_DIV_BY_4    2
#define TIMER3_PRESCALER_DIV_BY_8    3
/* timer1_reg_wr_mode */
#define TIMER3_RW_REG_8BIT_MODE      0
#define TIMER3_RW_REG_16BIT_MODE     1

/* ----------------Section : MACRO Functions Declerations------------------ */
#define TIMER3_MODULE_ENABLE()         (T3CONbits.TMR3ON = 1)
#define TIMER3_MODULE_DISABLE()        (T3CONbits.TMR3ON = 0)

#define TIMER3_TIMER_MODE_ENABLE()    (T3CONbits.TMR3CS = 0)
#define TIMER3_COUNTER_MODE_ENABLE()  (T3CONbits.TMR3CS = 1)

#define TIMER3_ASYNC_COUNTER_MODE_ENABLE()  (T3CONbits.T3SYNC = 1)
#define TIMER3_SYNC_COUNTER_MODE_ENABLE()   (T3CONbits.T3SYNC = 0)

#define TIMER2_RW_REG_8BIT_MODE_ENABLE     (T3CONbits.RD16=0)
#define TIMER3_RW_REG_16BIT_MODE_ENABLE    (T3CONbits.RD16=1)

#define TIMER_PRESCALER_SELECT(_PRESCALER_)  (T3CONbits.T3CKPS = _PRESCALER_)

/* ----------------Section : Data Types Declerations-------------- */
typedef struct{
#if TIMER3_INTERRUPT_FEATURE_ENABLE   ==  FEATURE_ENABLE
    void (* TMR3_InterruptHandler)(void);
  #if INTERRUPT_PRIORITY_LEVELS_ENABLE  ==   FEATURE_ENABLE
        interrupt_priority_cfg priority ;
  #endif
#endif
    uint16 timer3_preload_value ;
     uint8 timer3_mode :1;       
     uint8 timer3_counter_mode :1;
     uint8 timer3_reg_wr_mode :1;
     uint8 timer3_prescaler_value :2;
     uint8 timer1_reversed :3;
}timer3_t;


/* ------------------Section : Function Declerations---------------- */
Std_ReturnType Timer3_Init(const timer3_t * _timer);
Std_ReturnType Timer3_DeInit(const timer3_t * _timer);
Std_ReturnType Timer3_Write_value(const timer3_t * _timer,uint16 _value);
Std_ReturnType Timer3_Read_value(const timer3_t * _timer,uint16 *_value);
#endif	/* TIMER3_H */

