/* 
 * File:   ECU_layer_intialize.h
 * Author: moham
 *
 * Created on May 12, 2024, 2:33 AM
 */
#include "ECU_layer_intialize.h"



keypad_t keypad1 ={
  .keypad_row_pins[0].port = PORTC_INDEX,
  .keypad_row_pins[0].direction = GPIO_DIRECTION_OUTPUT ,
  .keypad_row_pins[0].pin =GPIO_PIN0,
  .keypad_row_pins[0].logic =GPIO_LOW,
  .keypad_row_pins[1].port = PORTC_INDEX,
  .keypad_row_pins[1].direction = GPIO_DIRECTION_OUTPUT ,
  .keypad_row_pins[1].pin =GPIO_PIN1,
  .keypad_row_pins[1].logic =GPIO_LOW,
  .keypad_row_pins[2].port = PORTC_INDEX,
  .keypad_row_pins[2].direction = GPIO_DIRECTION_OUTPUT ,
  .keypad_row_pins[2].pin =GPIO_PIN2,
  .keypad_row_pins[2].logic =GPIO_LOW,
  .keypad_row_pins[3].port = PORTC_INDEX,
  .keypad_row_pins[3].direction = GPIO_DIRECTION_OUTPUT ,
  .keypad_row_pins[3].pin =GPIO_PIN3,
  .keypad_row_pins[3].logic =GPIO_LOW,
  
  .keypad_columns_pins[0].port = PORTC_INDEX,
  .keypad_columns_pins[0].direction = GPIO_DIRECTION_INPUT ,
  .keypad_columns_pins[0].pin =GPIO_PIN4,
  .keypad_columns_pins[0].logic =GPIO_LOW,
  .keypad_columns_pins[1].port = PORTC_INDEX,
  .keypad_columns_pins[1].direction = GPIO_DIRECTION_INPUT ,
  .keypad_columns_pins[1].pin =GPIO_PIN5,
  .keypad_columns_pins[1].logic =GPIO_LOW,
  .keypad_columns_pins[2].port = PORTD_INDEX,
  .keypad_columns_pins[2].direction = GPIO_DIRECTION_INPUT ,
  .keypad_columns_pins[2].pin =GPIO_PIN0,
  .keypad_columns_pins[2].logic =GPIO_LOW,
  .keypad_columns_pins[3].port = PORTD_INDEX,
  .keypad_columns_pins[3].direction = GPIO_DIRECTION_INPUT ,
  .keypad_columns_pins[3].pin =GPIO_PIN1,
  .keypad_columns_pins[3].logic =GPIO_LOW,
};
