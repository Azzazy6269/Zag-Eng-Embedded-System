/* 
 * File:   application.c
 * Author: moham
 *
 * Created on April 22, 2024, 5:52 AM
 */


#include "application.h"

ccp_t ccp1_obj;
ccp_t ccp2_obj;
timer3_t timer3_obj;
volatile uint32 CCP1_Interrupt_Flag =0;

void CCP1_DefaultInterruptHandler(void){
    CCP1_Interrupt_Flag++;
}


int main() {
    Std_ReturnType ret=E_NOT_OK;
    application_intialize();
    ccp1_obj.CCP1_InterruptHandler = CCP1_DefaultInterruptHandler ;
    ccp1_obj.ccp_inst = CCP1_INST;
    ccp1_obj.CCP_mode =CCP_CAPTURE_MODE_SELECTED;
    ccp1_obj.CCP_mode_variant = CCP_CAPTURE_MODE_1_RISING_EDGE;
    ccp1_obj.ccp_capture_timer =CCP1_CCP2_TIMER3;
    ccp1_obj.ccp_pin.port = PORTC_INDEX;
    ccp1_obj.ccp_pin.pin = GPIO_PIN2;
    ccp1_obj.ccp_pin.direction = GPIO_DIRECTION_INPUT;
    //ret = CCP_Compare_Mode_Set_Value(&ccp1_obj,50000);
    
    timer3_obj.TMR3_InterruptHandler = NULL;
    timer3_obj.timer3_mode = TIMER3_TIMER_MODE;
    timer3_obj.timer3_prescaler_value = TIMER3_PRESCALER_DIV_BY_1;
    timer3_obj.timer3_preload_value = 0;
    timer3_obj.timer3_reg_wr_mode = TIMER3_RW_REG_16BIT_MODE;
    
    
    ret = Timer3_Init(&timer3_obj);
    ret =CCP_Init(&ccp1_obj);
    

    
    
    while(1){

    }
    return (EXIT_SUCCESS);
}



void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK ;
    
}



    