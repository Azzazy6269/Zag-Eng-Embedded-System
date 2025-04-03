/* 
 * File:   keypad.h
 * Author: moham
 *
 * Created on May 11, 2024, 9:15 PM
 */

#ifndef KEYPAD_H
#define	KEYPAD_H

/* Section : Includes */
#include "ECU_keypad_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/* Section : MACRO Declerations */
#define ECU_KEYPAD_ROWS      4
#define ECU_KEYPAD_COLUMNS   4

#define _XTAL_FREQ (uint64)3200000
/* Section : MACRO Functions Declerations */


/* Section : Data Types Declerations */
typedef struct{
    pin_config_t keypad_row_pins[ECU_KEYPAD_ROWS];
    pin_config_t keypad_columns_pins[ECU_KEYPAD_COLUMNS];
}keypad_t;

/* Section : Function Declerations */
Std_ReturnType keypad_intialize(const keypad_t *_keypad_obj);
Std_ReturnType keypad_get_value(const keypad_t *_keypad_obj,uint8 *value);
#endif	/* KEYPAD_H */

