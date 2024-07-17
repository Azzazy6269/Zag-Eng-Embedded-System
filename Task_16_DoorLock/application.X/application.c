/* 
 * File:   application.c
 * Author: moham
 *
 * Created on April 22, 2024, 5:52 AM
 */


#include "application.h"

uint8 volatile Push_button_status=ZERO_INIT;
uint8 volatile switch_status=ZERO_INIT;

int main() {
Std_ReturnType ret=E_NOT_OK;
application_intialize();

while(1){
    
    ret =button_read_state(&button,&Push_button_status);   
    if(!Push_button_status){
    Push_button_status =1;
    if(switch_status){
        ret =dc_motor_turn_right(&dc_motor_1);
    }else{
        ret =dc_motor_turn_left(&dc_motor_1);
    }
    uint8 temp =switch_status;
    do{
         ret =button_read_state(&switch__,&switch_status);   
    }while(temp==switch_status);
    ret = dc_motor_stop(&dc_motor_1);
    
    }
}
    return (EXIT_SUCCESS);
}

void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK ;
    ret = dc_motor_intialize(&dc_motor_1);
    ret = button_intialize(&button);
    ret = button_intialize(&switch__);
  
}