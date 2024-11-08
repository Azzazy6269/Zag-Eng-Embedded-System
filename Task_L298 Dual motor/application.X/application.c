/* 
 * File:   application.c
 * Author: moham
 *
 * Created on April 22, 2024, 5:52 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "application.h"
 

dc_motor_t dc_motor_1={
  .dc_motor_pin[0].port=PORTC_INDEX,
  .dc_motor_pin[0].pin=GPIO_PIN0,
  .dc_motor_pin[0].logic=DC_MOTOR_ON_STATUS,
  .dc_motor_pin[0].direction=GPIO_DIRECTION_OUTPUT,
  .dc_motor_pin[1].port=PORTC_INDEX,
  .dc_motor_pin[1].pin=GPIO_PIN1,
  .dc_motor_pin[1].logic=DC_MOTOR_ON_STATUS,
  .dc_motor_pin[1].direction=GPIO_DIRECTION_OUTPUT,
};
dc_motor_t dc_motor_2={
  .dc_motor_pin[0].port=PORTC_INDEX,
  .dc_motor_pin[0].pin=GPIO_PIN2,
  .dc_motor_pin[0].logic=DC_MOTOR_ON_STATUS,
  .dc_motor_pin[0].direction=GPIO_DIRECTION_OUTPUT,
  .dc_motor_pin[1].port=PORTC_INDEX,
  .dc_motor_pin[1].pin=GPIO_PIN3,
  .dc_motor_pin[1].logic=DC_MOTOR_ON_STATUS,
  .dc_motor_pin[1].direction=GPIO_DIRECTION_OUTPUT,
};

Std_ReturnType ret=E_NOT_OK;

int main() {
    application_intialize();
        Go_Forward();
        __delay_ms(10000);
        Turn_Right();
        __delay_ms(3000);
        Turn_Left();
        __delay_ms(4000);
        Go_Backward();
        __delay_ms(2000);
    while(1){
        
    }
    return (EXIT_SUCCESS);
}
void application_intialize(){
    ret = dc_motor_intialize(&dc_motor_1);
    ret = dc_motor_intialize(&dc_motor_2);
}

void Go_Forward(void){
    dc_motor_turn_right(&dc_motor_1);
    dc_motor_turn_right(&dc_motor_2);
}
void Go_Backward(void){
    dc_motor_turn_left(&dc_motor_1);
    dc_motor_turn_left(&dc_motor_2);
}
void Turn_Right(void){
    dc_motor_turn_right(&dc_motor_2);
    dc_motor_stop(&dc_motor_1);
}
void Turn_Left(void){
    dc_motor_turn_right(&dc_motor_1);
    dc_motor_stop(&dc_motor_2);
}