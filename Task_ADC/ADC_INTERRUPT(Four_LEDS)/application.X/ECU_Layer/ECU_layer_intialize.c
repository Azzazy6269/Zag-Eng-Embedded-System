/* 
 * File:   ECU_layer_intialize.h
 * Author: moham
 *
 * Created on May 12, 2024, 2:33 AM
 */
#include "ECU_layer_intialize.h"



led_t led0 ={ 
    .port_name = PORTC_INDEX ,
    .pin = GPIO_PIN0,
    .led_status = GPIO_LOW
};
led_t led1 ={ 
    .port_name = PORTC_INDEX ,
    .pin = GPIO_PIN1,
    .led_status = GPIO_LOW
};
led_t led2 ={ 
    .port_name = PORTC_INDEX ,
    .pin = GPIO_PIN2,
    .led_status = GPIO_LOW
};
led_t led3 ={ 
    .port_name = PORTC_INDEX ,
    .pin = GPIO_PIN3,
    .led_status = GPIO_LOW
};

