/* 
 * File:   led.c
 * Author: moham
 *
 * Created on April 22, 2024, 6:14 PM
 */
#include "led.h"
/**
 * @breif intialize the assigned pin to be output and turn the led off
 * @param led
 * @return status of the f unction
 *          E_OK :the function done successfully
 *          E_NOT_OK :the function had an issue while performing the action
 */
Std_ReturnType led_intialize(const led_t *led){
    Std_ReturnType ret = E_OK ;
    if(NULL == led){
        ret = E_NOT_OK ;
    }else{
        pin_config_t pin_obj ={
        .port      = led->port_name,
        .pin       = led->pin,
        .direction = GPIO_DIRECTION_OUTPUT,
        .logic     = led->led_status
    };
        gpio_pin_intialize(&pin_obj);
    }
    return ret ;
}
/**
 * @breif turn the led on
 * @param led
 * @return status of the function
 *          E_OK :the function done successfully
 *          E_NOT_OK :the function had an issue while performing the action
 */
Std_ReturnType led_turn_on(const led_t *led){
    Std_ReturnType ret = E_OK ;
    if(NULL == led){
        ret = E_NOT_OK ;
    }else{
      pin_config_t pin_obj ={
        .port      = led->port_name,
        .pin       = led->pin,
        .direction = GPIO_DIRECTION_OUTPUT,
        .logic     = led->led_status
    };
      gpio_pin_write_logic(&pin_obj,GPIO_HIGH);
    }
    return ret ;
}

/**
 * @brief turn the led off
 * @param led
 * @return status of the function
 *          E_OK :the function done successfully
 *          E_NOT_OK :the function had an issue while performing the action
 */
Std_ReturnType led_turn_off(const led_t *led){
    Std_ReturnType ret = E_OK ;
    if(NULL == led){
        ret = E_NOT_OK ;
    }else{
        pin_config_t pin_obj ={
        .port      = led->port_name,
        .pin       = led->pin,
        .direction = GPIO_DIRECTION_OUTPUT,
        .logic     = led->led_status
    };
      gpio_pin_write_logic(&pin_obj,GPIO_LOW);
    }
    return ret ;

}
/**
 * @breif turn the led toggle
 * @param led
 * @return status of the function
 *          E_OK :the function done successfully
 *          E_NOT_OK :the function had an issue while performing the action
 */
Std_ReturnType led_turn_toggle(const led_t *led){
    Std_ReturnType ret = E_OK ;
    if(NULL == led){
        ret = E_NOT_OK ;
    }else{
        pin_config_t pin_obj ={
        .port      = led->port_name,
        .pin       = led->pin,
        .direction = GPIO_DIRECTION_OUTPUT,
        .logic     = led->led_status
    };
      gpio_pin_toggle_logic(&pin_obj);
    }
    return ret ;
}




