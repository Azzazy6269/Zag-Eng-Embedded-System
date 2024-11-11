/* 
 * File:   application.c
 * Author: moham
 *
 * Created on April 22, 2024, 5:52 AM
 */


#include "application.h"
volatile uint16 flagTMR1 =0;
timer0_t timer0_counter_obj = {
    .TMR0_InterruptHandler = Timer0_DefaultInterruptHandler,
    .prescaler_enable = TIMER0_PRESCALER_DISABLE_CFG,
    .prescaler_value = TIMER_PRESCALER_DIV_BY_32 ,
    .timer0_counter_edge = TIMER0_RISING_EDGE_CFG,
    .timer0_mode = TIMER0_COUNTER_MODE,
    .timer0_preload_value =15536,
    .timer0_register_size = TIMER0_16BIT_REGISTER_MODE, 
};
timer1_t timer1_obj={
  .TMR1_InterruptHandler = Timer1_DefaultInterruptHandler,
  .prescaler_value =TIMER1_PRESCALER_DIV_BY_4,
  .timer1_preload_value =15536,
  .timer1_mode =TIMER1_TIMER_MODE,
  .timer1_osc_cfg =TIMER1_OSCILLATOR_DISABLE,
  .timer1_reg_wr_mode =TIMER1_RW_REG_16BIT_MODE,
};
timer1_t counter1_obj={
  .TMR1_InterruptHandler = Timer1_DefaultInterruptHandler,
  .prescaler_value =TIMER1_PRESCALER_DIV_BY_1,
  .timer1_counter_mode =TIMER1_ASYNC_COUNTER_MODE,
  .timer1_preload_value =0,
  .timer1_mode =TIMER1_TIMER_MODE,
  .timer1_osc_cfg =TIMER1_OSCILLATOR_DISABLE,
  .timer1_reg_wr_mode =TIMER1_RW_REG_16BIT_MODE,
};


int main() {
    Std_ReturnType ret=E_NOT_OK;
    application_intialize();
    
    while(1){
    }
    return (EXIT_SUCCESS);
}
void Timer0_DefaultInterruptHandler(void){
    
    }

void Timer1_DefaultInterruptHandler(void){
    flagTMR1++;
    led_turn_toggle(&led1);
    }

void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK ;
    ret = Timer1_Init(&timer1_obj);
    ret = led_intialize(&led1);
    
}



    