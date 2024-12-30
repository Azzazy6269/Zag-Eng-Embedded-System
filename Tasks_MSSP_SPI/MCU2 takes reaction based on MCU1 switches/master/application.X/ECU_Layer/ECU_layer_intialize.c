/* 
 * File:   ECU_layer_intialize.h
 * Author: moham
 *
 * Created on May 12, 2024, 2:33 AM
 */
#include "ECU_layer_intialize.h"


led_t led1={
    .port_name =PORTD_INDEX,
    .pin = GPIO_PIN0,
    .led_status = LED_OFF
};

button_t btn1 ={
    .button_pin.port = PORTD_INDEX,
    .button_pin.pin = GPIO_PIN0,
    .button_pin.direction = GPIO_DIRECTION_INPUT,
    .button_connection = BUTTON_ACTIVE_HIGH,
    .button_state = BUTTON_RELEASED 
};
button_t btn2 ={
    .button_pin.port = PORTD_INDEX,
    .button_pin.pin = GPIO_PIN2,
    .button_pin.direction = GPIO_DIRECTION_INPUT,
    .button_connection = BUTTON_ACTIVE_HIGH,
    .button_state = BUTTON_RELEASED 
};