/* 
 * File:   Timer1.h
 * Author: smart
 *
 * Created on 22 Aug, 2024, 01:00 ?
 */

#ifndef TIMER1_H
#define	TIMER1_H

/* Section : Includes */
#include "../GPIO/hal_gpio.h"
#include "../Interrupt/Internal_interrupt.h"
#include "../mcal_std_types.h"
/* -------------- Section : MACRO Declerations --------------- */
/* timer1_mode */
#define TIMER1_TIMER_MODE            0
#define TIMER1_COUNTER_MODE          1
/* timer1_counter_mode */
#define TIMER1_ASYNC_COUNTER_MODE    1
#define TIMER1_SYNC_COUNTER_MODE     0
/*timer1_osc_cfg */
#define TIMER1_OSCILLATOR_ENABLE     1
#define TIMER1_OSCILLATOR_DISABLE    0
/* timer1_reg_wr_mode */
#define TIMER1_RW_REG_8BIT_MODE      0
#define TIMER1_RW_REG_16BIT_MODE     1
/* prescaler_value */
#define TIMER1_PRESCALER_DIV_BY_1    0
#define TIMER1_PRESCALER_DIV_BY_2    1
#define TIMER1_PRESCALER_DIV_BY_4    2
#define TIMER1_PRESCALER_DIV_BY_8    3

/* ------------- Section : MACRO Functions Declerations ----------- */
#define TIMER1_MODULE_ENABLE()         (T1CONbits.TMR1ON =1)
#define TIMER1_MODULE_DISABLE()        (T1CONbits.TMR1ON =0)

#define TIMER1_TIMER_MODE_ENABLE()    (T1CONbits.TMR1CS =0)
#define TIMER1_COUNTER_MODE_ENABLE()  (T1CONbits.TMR1CS =1)

#define TIMER1_ASYNC_COUNTER_MODE_ENABLE()  (T1CONbits.T1SYNC = 1)
#define TIMER1_SYNC_COUNTER_MODE_ENABLE()   (T1CONbits.T1SYNC = 0)

#define TIMER1_OSC_HW_ENABLE()            (T1CONbits.T1OSCEN = 1)
#define TIMER1_OSC_HW_DISABLE()           (T1CONbits.T1OSCEN = 0)

#define TIMER1_RW_REG_8BIT_MODE_ENABLE     (T1CONbits.RD16=0)
#define TIMER1_RW_REG_16BIT_MODE_ENABLE    (T1CONbits.RD16=1)

#define TIMER_PRESCALER_SELECT(_PRESCALER_)  (T1CONbits.T1CKPS = _PRESCALER_)



/* This function returns 1 if the clock source is Timer1 Oscillator 
 *                       0 if another clock source  */
#define TIMER1_SYSTEM_CLK_STATUS()           (T1CONbits.T1RUN)
/* ------------- Section : Data Types Declerations  -------------*/
typedef struct{
#if TIMER1_INTERRUPT_FEATURE_ENABLE   ==  FEATURE_ENABLE
    void (* TMR1_InterruptHandler)(void);
  #if INTERRUPT_PRIORITY_LEVELS_ENABLE  ==   FEATURE_ENABLE
        interrupt_priority_cfg priority ;
  #endif
#endif
     uint16 timer1_preload_value ;
     uint8 timer1_mode :1;       
     uint8 timer1_counter_mode :1;
     uint8 timer1_osc_cfg : 1;
     uint8 timer1_reg_wr_mode :1;
     uint8 prescaler_value :2;
     uint8 timer1_reversed :2;
}timer1_t;

/* ---------- Section : Function Declerations --------------- */
Std_ReturnType Timer1_Init(const timer1_t * _timer);
Std_ReturnType Timer1_DeInit(const timer1_t * _timer);
Std_ReturnType Timer1_Write_value(const timer1_t * _timer,uint16 _value);
Std_ReturnType Timer1_Read_value(const timer1_t * _timer,uint16 *_value);


#endif	/* TIMER1_H */

