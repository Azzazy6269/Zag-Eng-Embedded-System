/* 
 * File:   relay.c
 * Author: moham
 *
 * Created on May 7, 2024, 11:58 PM
 */
#include "relay.h"


/**
 * @breif intialize the assigned pin to be output and turn tun the relay off 
 * @param _relay
 * @return status of the f unction
 *          E_OK :the function done successfully
 *          E_NOT_OK :the function had an issue while performing the action
 */
Std_ReturnType relay_intialize(const relay_t *_relay){
    Std_ReturnType ret = E_OK ;
    if(NULL == _relay){
        ret = E_NOT_OK ;
    }else{
         pin_config_t pin_obj ={
        .port      = _relay->relay_port,
        .pin       = _relay->relay_pin,
        .direction = GPIO_DIRECTION_OUTPUT,
        .logic     = _relay->relay_status
    };
         gpio_pin_intialize(&pin_obj);
    }
    return ret;
}

/**
 * @breif turn on the relay
 * @param led
 * @return status of the f unction
 *          E_OK :the function done successfully
 *          E_NOT_OK :the function had an issue while performing the action
 */
Std_ReturnType relay_turn_on(const relay_t *_relay){
    Std_ReturnType ret = E_OK ;
    if(NULL == _relay){
        ret = E_NOT_OK ;
    }else{
         pin_config_t pin_obj ={
        .port      = _relay->relay_port,
        .pin       = _relay->relay_pin,
        .direction = GPIO_DIRECTION_OUTPUT,
        .logic     = _relay->relay_status
    };
      gpio_pin_write_logic(&pin_obj,GPIO_HIGH);   
    }
    return ret;
}

/**
 * @breif turn off the relay
 * @param led
 * @return status of the f unction
 *          E_OK :the function done successfully
 *          E_NOT_OK :the function had an issue while performing the action
 */
Std_ReturnType relay_turn_off(const relay_t *_relay){
    Std_ReturnType ret = E_OK ;
    if(NULL == _relay){
        ret = E_NOT_OK ;
    }else{
        pin_config_t pin_obj ={
        .port      = _relay->relay_port,
        .pin       = _relay->relay_pin,
        .direction = GPIO_DIRECTION_OUTPUT,
        .logic     = _relay->relay_status
    };
      gpio_pin_write_logic(&pin_obj,GPIO_LOW);  
    }
    return ret;
}