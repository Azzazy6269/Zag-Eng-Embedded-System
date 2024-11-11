/* 
 * File:   application.c
 * Author: moham
 *
 * Created on April 22, 2024, 5:52 AM
 */


#include "application.h"
volatile uint16 PushButtonCounter =0;
timer0_t timer0_counter_obj = {
    .TMR0_InterruptHandler=Timer0_DefaultInterruptHandler,
    .prescaler_enable = TIMER0_PRESCALER_DISABLE_CFG,
    .prescaler_value = TIMER_PRESCALER_DIV_BY_32 ,
    .timer0_counter_edge = TIMER0_RISING_EDGE_CFG,
    .timer0_mode = TIMER0_COUNTER_MODE,
    .timer0_preload_value =0,
    .timer0_register_size = TIMER0_16BIT_REGISTER_MODE, 
};

int main() {
    Std_ReturnType ret=E_NOT_OK;
    application_intialize();
    
    while(1){
        ret = Timer0_Read_value(&timer0_counter_obj,&PushButtonCounter);
        if(PushButtonCounter%5==0) {(led_turn_on(&led1));}
        else {led_turn_off(&led1);}
    }
    return (EXIT_SUCCESS);
}
void Timer0_DefaultInterruptHandler(void){
    
    }


void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK ;
    ret = Timer0_Init(&timer0_counter_obj);
    ret = led_intialize(&led1);
    
}



    