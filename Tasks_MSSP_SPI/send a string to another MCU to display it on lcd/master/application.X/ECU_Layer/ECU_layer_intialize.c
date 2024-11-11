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

