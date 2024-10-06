/* 
 * File:   application.c
 * Author: moham
 *
 * Created on April 22, 2024, 5:52 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "application.h"
#include "ECU_Layer/relay/relay.h"
#include "ECU_Layer/DC_motor/DC_motor.h"
 





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
    while(1){
        ret = dc_motor_turn_right(&dc_motor_1);
        ret = dc_motor_turn_left(&dc_motor_2);
        __delay_ms(3000);
        ret = dc_motor_turn_right(&dc_motor_2);
        ret = dc_motor_turn_left(&dc_motor_1);
        __delay_ms(3000);
        ret = dc_motor_stop(&dc_motor_1);
        ret = dc_motor_stop(&dc_motor_2);
        __delay_ms(3000);
    }
    return (EXIT_SUCCESS);
}
void application_intialize(){
    ret = dc_motor_intialize(&dc_motor_1);
    ret = dc_motor_intialize(&dc_motor_2);
}

