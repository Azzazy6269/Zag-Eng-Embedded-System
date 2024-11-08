/* 
 * File:   application.c
 * Author: moham
 *
 * Created on April 22, 2024, 5:52 AM
 */


#include "application.h"

ccp1_t ccp1_obj;
timer2_t timer2_obj;


int main() {
    Std_ReturnType ret=E_NOT_OK;
    application_intialize();
    ccp1_obj.CCP1_mode =CCP1_PWM_MODE_SELECTED;
    ccp1_obj.CCP1_mode_variant = CCP1_PWM_MODE;
    ccp1_obj.PWM_Frequency=20000;
    ccp1_obj.ccp_pin.port = PORTC_INDEX;
    ccp1_obj.ccp_pin.pin = GPIO_PIN2;
    ccp1_obj.ccp_pin.direction = GPIO_DIRECTION_OUTPUT;
    ccp1_obj.timer2_prescaler_value = CCP1_TIMER2_PRESCALER_DIV_BY_1 ;
    ccp1_obj.timer2_postscaler_value = CCP1_TIMER2_POSTSCALER_DIV_BY_1 ;
    ret =CCP1_Init(&ccp1_obj);
    
    timer2_obj.TMR2_InterruptHandler = NULL;
    timer2_obj.timer2_postscaler_value = TIMER2_POSTSCALER_DIV_BY_1;
    timer2_obj.timer2_prescaler_value = TIMER2_PRESCALER_DIV_BY_1;
    timer2_obj.timer2_preload_value = 0;
    ret = Timer2_Init(&timer2_obj);
    
    

ret = CCP1_PWM1_Set_Duty(50);
    ret = CCP1_PWM1_Start();
    
    while(1){

    }
    return (EXIT_SUCCESS);
}


void Timer3_DefaultInterruptHandler(void){
    led_turn_toggle(&led1);
    }

void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK ;
    ret = led_intialize(&led1);
    
}



    