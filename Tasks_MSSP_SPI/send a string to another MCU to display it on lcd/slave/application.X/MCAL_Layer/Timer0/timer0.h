/* 
 * File:   timer0.h
 * Author: smart
 *
 * Created on 19 Aug, 2024, 01:23 ?
 */

#ifndef TIMER0_H
#define	TIMER0_H

/* Section : Includes */
#include "../GPIO/hal_gpio.h"
#include "../Interrupt/Internal_interrupt.h"
#include "../mcal_std_types.h"
/* Section : MACRO Declerations */
#define TIMER0_PRESCALER_ENABLE_CFG 1
#define TIMER0_PRESCALER_DISABLE_CFG 0

#define TIMER0_RISING_EDGE_CFG 1
#define TIMER0_FALLING_EDGE_CFG 0

#define TIMER0_TIMER_MODE 1
#define TIMER0_COUNTER_MODE 0

#define TIMER0_8BIT_REGISTER_MODE 1
#define TIMER0_16BIT_REGISTER_MODE 0

/* Section : MACRO Functions Declerations */
#define TIMER0_PRESCALER_ENABLE()     (T0CONbits.PSA = 0)
#define TIMER0_PRESCALER_DISABLE()    (T0CONbits.PSA = 1)

#define TIMER0_RISING_EDGE_ENABLE()   (T0CONbits.T0SE = 0)
#define TIMER0_FALLING_EDGE_ENABLE()  (T0CONbits.T0SE = 1)

#define TIMER0_TIMER_MODE_ENABLE()    (T0CONbits.T0CS =0)
#define TIMER0_COUNTER_MODE_ENABLE()  (T0CONbits.T0CS =1)

#define TIMER0_8BIT_REGISTER_MODE_ENABLE()      (T0CONbits.T08BIT =1)
#define TIMER0_16BIT_REGISTER_MODE_ENABLE()     (T0CONbits.T08BIT =0)

#define TIMER0_MODULE_ENABLE()         (T0CONbits.TMR0ON =1)
#define TIMER0_MODULE_DISABLE()        (T0CONbits.TMR0ON =0)

/* Section : Data Types Declerations */
typedef enum {
    TIMER_PRESCALER_DIV_BY_2 =0,
    TIMER_PRESCALER_DIV_BY_4,
    TIMER_PRESCALER_DIV_BY_8,
    TIMER_PRESCALER_DIV_BY_16,
    TIMER_PRESCALER_DIV_BY_32,
    TIMER_PRESCALER_DIV_BY_64,
    TIMER_PRESCALER_DIV_BY_128,
    TIMER_PRESCALER_DIV_BY_256,
}timer0_prescaler_select_t;


typedef struct {
#if TIMER0_INTERRUPT_FEATURE_ENABLE   ==  FEATURE_ENABLE
    void (* TMR0_InterruptHandler)(void);
    #if INTERRUPT_PRIORITY_LEVELS_ENABLE  ==   FEATURE_ENABLE
        interrupt_priority_cfg priority ;
    #endif
#endif
    timer0_prescaler_select_t prescaler_value;
    uint16 timer0_preload_value ;
    uint8 prescaler_enable :1;
    uint8 timer0_counter_edge :1;
    uint8 timer0_mode :1;
    uint8 timer0_register_size :1;
    uint8 timer0_reserved :4;
}timer0_t;
/* Section : Function Declerations */
Std_ReturnType Timer0_Init(const timer0_t * _timer);
Std_ReturnType Timer0_DeInit(const timer0_t * _timer);
Std_ReturnType Timer0_Write_value(const timer0_t * _timer,uint16 _value);
Std_ReturnType Timer0_Read_value(const timer0_t * _timer,uint16 *_value);

#endif	/* TIMER0_H */

