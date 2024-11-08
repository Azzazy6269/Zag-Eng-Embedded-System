/* 
 * File:   application.c
 * Author: moham
 *
 * Created on April 22, 2024, 5:52 AM
 */


#include "application.h"

uint8 x=0;
ccp_t ccp1_obj;
ccp_t ccp2_obj;
timer3_t timer3_obj;


void CCP1_DefaultInterruptHandler(void){
    Timer3_Write_value(&timer3_obj,0);
    if(x==0){
        CCP_Compare_Mode_Set_Value(&ccp1_obj,10000);
        CCP1_SET_MODE(CCP_COMPARE_MODE_SET_PIN_LOW);
        x++;
    }else if(x==1){
        CCP_Compare_Mode_Set_Value(&ccp1_obj,40000);
        CCP1_SET_MODE(CCP_COMPARE_MODE_SET_PIN_HIGH);
        x=0;
    }
}
void Timer3_DefaultInterruptHandler(void){
    
}



int main() {
    Std_ReturnType ret=E_NOT_OK;
    application_intialize();
    ccp1_obj.CCP1_InterruptHandler = CCP1_DefaultInterruptHandler ;
    ccp1_obj.ccp_inst = CCP1_INST;
    ccp1_obj.CCP_mode =CCP_COMPARE_MODE_SELECTED;
    ccp1_obj.CCP_mode_variant = CCP_COMPARE_MODE_TOGGLE_ON_MATCH;
    ccp1_obj.ccp_capture_timer =CCP1_CCP2_TIMER3;
    ccp1_obj.ccp_pin.port = PORTC_INDEX;
    ccp1_obj.ccp_pin.pin = GPIO_PIN2;
    ccp1_obj.ccp_pin.direction = GPIO_DIRECTION_OUTPUT;
    ccp1_obj.ccp_pin.logic = GPIO_HIGH;

    
    timer3_obj.TMR3_InterruptHandler = Timer3_DefaultInterruptHandler;
    timer3_obj.timer3_mode = TIMER3_TIMER_MODE;
    timer3_obj.timer3_prescaler_value = TIMER3_PRESCALER_DIV_BY_1;
    timer3_obj.timer3_preload_value = 0;
    timer3_obj.timer3_reg_wr_mode = TIMER3_RW_REG_16BIT_MODE;
    
    ret = CCP_Compare_Mode_Set_Value(&ccp1_obj,40000);
    ret = Timer3_Init(&timer3_obj);
    ret =CCP_Init(&ccp1_obj);
    

    while(1){
        
    }
    return (EXIT_SUCCESS);
}



void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK ;
    
}



    