/* 
 * File:   button.c
 * Author: moham
 *
 * Created on May 5, 2024, 7:38 PM
 */
#include "button.h"
/**
 * @breif intialize the assigned pin to be input 
 * @param btn
 * @return status of the function
 *          E_OK :the function done successfully
 *          E_NOT_OK :the function had an issue while performing the action
 */
Std_ReturnType button_intialize(const button_t *btn){
    Std_ReturnType ret = E_OK ;
    if(NULL == btn){
        ret = E_NOT_OK ;
    }else{
        ret = gpio_pin_direction_intialize(&(btn ->button_pin));
        
    }
    return ret ;
}
/**
 * @breif read the button status
 * @param led
 * @return status of the f unction
 *          E_OK :the function done successfully
 *          E_NOT_OK :the function had an issue while performing the action
 */
Std_ReturnType button_read_state(const button_t *btn ,button_state_t *btn_state){
     Std_ReturnType ret = E_OK ;
     logic_t pin_logic_status = GPIO_LOW ;
    if(NULL == btn || NULL==btn_state){
        ret = E_NOT_OK ;
    }else{
        gpio_pin_read_logic(&(btn ->button_pin),&pin_logic_status);
        if(BUTTON_ACTIVE_HIGH == btn ->button_connection){
            if(GPIO_HIGH == pin_logic_status){
                *btn_state = BUTTON_PRESSED;
            }else{
                *btn_state = BUTTON_RELEASED;
            }
        }else if (BUTTON_ACTIVE_LOW == btn ->button_connection){
            if(GPIO_HIGH == pin_logic_status){
                *btn_state = BUTTON_RELEASED ;
            }else{
                *btn_state = BUTTON_PRESSED;
            }
        }else{  /* Nothing */  }
    }
    return ret ;
}