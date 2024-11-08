/* 
 * File:   DC_motor.c
 * Author: moham
 *
 * Created on May 8, 2024, 6:42 PM
 */

#include "DC_motor.h"

static pin_config_t motor_pin1;
static pin_config_t motor_pin2;
/**
 * @breif intialize the assigned pin 
 * @param _relay
 * @return status of the function
 *          E_OK :the function done successfully
 *          E_NOT_OK :the function had an issue while performing the action
 */
Std_ReturnType dc_motor_intialize (const dc_motor_t * _dc_motor){
     Std_ReturnType ret = E_OK ;
     if(NULL==_dc_motor){
                 ret = E_NOT_OK;

     }else{
         gpio_pin_intialize(&(_dc_motor->dc_motor_pin[0]));
         gpio_pin_intialize(&(_dc_motor->dc_motor_pin[1]));
     }
     return E_OK;
}

/**
 * @breif turn the motor to the right 
 * @param _relay
 * @return status of the function
 *          E_OK :the function done successfully
 *          E_NOT_OK :the function had an issue while performing the action
 */
Std_ReturnType dc_motor_turn_right (const dc_motor_t * _dc_motor){
    Std_ReturnType ret = E_OK ;
     if(NULL==_dc_motor){
           ret = E_NOT_OK;
     }else{
         gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[0]),GPIO_HIGH);
         gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[1]),GPIO_LOW);
     }
    return E_OK;
}

/**
 * @breif turn the motor to the left
 * @param _relay
 * @return status of the function
 *          E_OK :the function done successfully
 *          E_NOT_OK :the function had an issue while performing the action
 */
Std_ReturnType dc_motor_turn_left (const dc_motor_t * _dc_motor){
    Std_ReturnType ret = E_OK ;
     if(NULL==_dc_motor){
            ret = E_NOT_OK;
     }else{
         gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[0]),GPIO_LOW);
         gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[1]),GPIO_HIGH);
     }
    return E_OK;
}

/**
 * @breif stop the motor
 * @param _relay
 * @return status of the function
 *          E_OK :the function done successfully
 *          E_NOT_OK :the function had an issue while performing the action
 */
Std_ReturnType dc_motor_stop (const dc_motor_t * _dc_motor){
    Std_ReturnType ret = E_OK ;
     if(NULL==_dc_motor){
            ret = E_NOT_OK;
     }else{
         gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[0]),GPIO_LOW);
         gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[1]),GPIO_LOW);
     }
    return E_OK;
}
