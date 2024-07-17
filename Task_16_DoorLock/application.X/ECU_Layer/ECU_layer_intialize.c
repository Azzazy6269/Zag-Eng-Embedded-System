/* 
 * File:   ECU_layer_intialize.h
 * Author: moham
 *
 * Created on May 12, 2024, 2:33 AM
 */
#include "ECU_layer_intialize.h"



button_t button = {
    .button_pin.port     = PORTC_INDEX,
    .button_pin.pin      = GPIO_PIN0,
    .button_pin.direction= GPIO_DIRECTION_INPUT,
    .button_state        = BUTTON_RELEASED,
    .button_connection   =BUTTON_ACTIVE_HIGH
};

button_t switch__ = {
    .button_pin.port      = PORTC_INDEX,
    .button_pin.pin       = GPIO_PIN1,
    .button_pin.direction = GPIO_DIRECTION_INPUT ,
    .button_state         = BUTTON_RELEASED,
    .button_connection    =BUTTON_ACTIVE_HIGH
};

dc_motor_t dc_motor_1={
  .dc_motor_pin[0].port=PORTC_INDEX,
  .dc_motor_pin[0].pin=GPIO_PIN6,
  .dc_motor_pin[0].logic=DC_MOTOR_OFF_STATUS,
  .dc_motor_pin[0].direction=GPIO_DIRECTION_OUTPUT,
  .dc_motor_pin[1].port=PORTC_INDEX,
  .dc_motor_pin[1].pin=GPIO_PIN7,
  .dc_motor_pin[1].logic=DC_MOTOR_OFF_STATUS,
  .dc_motor_pin[1].direction=GPIO_DIRECTION_OUTPUT,
};