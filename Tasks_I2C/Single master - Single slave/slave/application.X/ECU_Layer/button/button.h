/* 
 * File:   button.h
 * Author: moham
 *
 * Created on May 5, 2024, 7:38 PM
 */

#ifndef BUTTON_H
#define	BUTTON_H


/* Section : Includes */
#include "ECU_button_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/* Section : MACRO Declerations */


/* Section : MACRO Functions Declerations */


/* Section : Data Types Declerations */
typedef enum {
    BUTTON_PRESSED,
    BUTTON_RELEASED
}button_state_t;

typedef enum {
    BUTTON_ACTIVE_HIGH,
    BUTTON_ACTIVE_LOW
}button_active_t;

typedef struct{
    pin_config_t button_pin;
    button_state_t button_state;
    button_active_t button_connection;     
}button_t;

/* Section : Function Declerations */
Std_ReturnType button_intialize(const button_t *btn);
Std_ReturnType button_read_state(const button_t *btn ,button_state_t *btn_state);


#endif	/* BUTTON_H */

