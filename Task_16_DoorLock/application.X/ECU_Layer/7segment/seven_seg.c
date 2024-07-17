/* 
 * File:   seven_seg.c
 * Author: moham
 *
 * Created on May 9, 2024, 10:46 PM
 */

#include "seven_seg.h"

/**
 * @breif intialize the assigned 4 pin to be the input of the decoder
 * @param led
 * @return status of the f unction
 *          E_OK :the function done successfully
 *          E_NOT_OK :the function had an issue while performing the action
 */
Std_ReturnType seven_segment_intialize(const segment_t *seg){
    Std_ReturnType ret=E_OK;
    if(NULL==seg){
        ret = E_NOT_OK;
    }
    else{
       ret= gpio_pin_intialize(&(seg->segment_pins[0]));
       ret= gpio_pin_intialize(&(seg->segment_pins[1]));
       ret= gpio_pin_intialize(&(seg->segment_pins[2]));
       ret= gpio_pin_intialize(&(seg->segment_pins[3]));
    }
    return ret;
}

/**
 * @breif write a number on the 7segment
 * @param led
 * @return status of the f unction
 *          E_OK :the function done successfully
 *          E_NOT_OK :the function had an issue while performing the action
 */
Std_ReturnType seven_segment_write_number(const segment_t *seg,uint8 number){
    Std_ReturnType ret=E_OK;
    if(NULL==seg || number > 9 ){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_write_logic(&(seg->segment_pins[0]),number & 0x01);
        ret = gpio_pin_write_logic(&(seg->segment_pins[1]),(number>>1) & 0x01);
        ret = gpio_pin_write_logic(&(seg->segment_pins[2]),(number>>2) & 0x01);
        ret = gpio_pin_write_logic(&(seg->segment_pins[3]),(number>>3) & 0x01);
    }
    return ret;
}
