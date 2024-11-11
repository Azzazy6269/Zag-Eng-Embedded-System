/* 
 * File:   ECU_layer_intialize.h
 * Author: moham
 *
 * Created on May 12, 2024, 2:33 AM
 */
#include "ECU_layer_intialize.h"


chr_lcd_4bits_t lcd1 ={
    .lcd_rs.port=PORTD_INDEX,
    .lcd_rs.pin=GPIO_PIN0,
    .lcd_rs.direction=GPIO_DIRECTION_OUTPUT,
    .lcd_rs.logic=GPIO_LOW,
    .lcd_en.port=PORTD_INDEX,
    .lcd_en.pin=GPIO_PIN1,
    .lcd_en.direction=GPIO_DIRECTION_OUTPUT,
    .lcd_en.logic=GPIO_LOW,
    .lcd_data[0].port=PORTD_INDEX,
    .lcd_data[0].pin=GPIO_PIN2,
    .lcd_data[0].direction=GPIO_DIRECTION_OUTPUT,
    .lcd_data[0].logic=GPIO_LOW,
    .lcd_data[1].port=PORTD_INDEX,
    .lcd_data[1].pin=GPIO_PIN3,
    .lcd_data[1].direction=GPIO_DIRECTION_OUTPUT,
    .lcd_data[1].logic=GPIO_LOW,
    .lcd_data[2].port=PORTD_INDEX,
    .lcd_data[2].pin=GPIO_PIN4,
    .lcd_data[2].direction=GPIO_DIRECTION_OUTPUT,
    .lcd_data[2].logic=GPIO_LOW,
    .lcd_data[3].port=PORTD_INDEX,
    .lcd_data[3].pin=GPIO_PIN5,
    .lcd_data[3].direction=GPIO_DIRECTION_OUTPUT,
    .lcd_data[3].logic=GPIO_LOW
};
