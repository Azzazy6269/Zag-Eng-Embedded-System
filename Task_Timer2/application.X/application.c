/* 
 * File:   application.c
 * Author: moham
 *
 * Created on April 22, 2024, 5:52 AM
 */


#include "application.h"
#include "MCAL_Layer/Timer2/Timer2.h"
volatile uint16 flagTMR2 =0, readCOUNTER=0;
timer2_t timer2_obj; 


int main() {
    Std_ReturnType ret=E_NOT_OK;
    application_intialize();
    
    timer2_obj.TMR2_InterruptHandler = Timer2_DefaultInterruptHandler;
    timer2_obj.timer2_postscaler_value = TIMER2_POSTSCALER_DIV_BY_16;
    timer2_obj.timer2_prescaler_value = TIMER2_PRESCALER_DIV_BY_1;
    timer2_obj.timer2_preload_value = 249;
    Timer2_Init(&timer2_obj);
    
    while(1){
    }
    return (EXIT_SUCCESS);
}


void Timer2_DefaultInterruptHandler(void){
    flagTMR2++;
    led_turn_toggle(&led1);
    }

void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK ;
    ret = led_intialize(&led1);
    
}



    