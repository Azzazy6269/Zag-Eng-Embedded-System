/* 
 * File:   application.c
 * Author: moham
 *
 * Created on April 22, 2024, 5:52 AM
 */


#include "application.h"
volatile uint16 flagTMR3 =0, readCOUNTER=0;
timer3_t timer3_obj; 


int main() {
    Std_ReturnType ret=E_NOT_OK;
    application_intialize();
    
    timer3_obj.TMR3_InterruptHandler = Timer3_DefaultInterruptHandler;
    timer3_obj.timer3_mode = TIMER3_TIMER_MODE;
    timer3_obj.timer3_preload_value=15536;
    timer3_obj.timer3_prescaler_value=TIMER3_PRESCALER_DIV_BY_8;
    timer3_obj.timer3_reg_wr_mode=TIMER3_RW_REG_16BIT_MODE;
    Timer3_Init(&timer3_obj);
    
    while(1){
    }
    return (EXIT_SUCCESS);
}


void Timer3_DefaultInterruptHandler(void){
    flagTMR3++;
    led_turn_toggle(&led1);
    }

void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK ;
    ret = led_intialize(&led1);
    
}



    