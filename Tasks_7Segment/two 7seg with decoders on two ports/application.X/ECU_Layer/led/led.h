/* 
 * File:   led.h
 * Author: moham
 *
 * Created on April 22, 2024, 6:14 PM
 */

#ifndef LED_H
#define	LED_H

/* Section : Includes */
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "ECU_led_cfg.h"

/* Section : MACRO Declerations */


/* Section : MACRO Functions Declerations */


/* Section : Data Types Declerations */
typedef enum {
    LED_OFF =0 ,
    LED_ON
}led_status_t;

typedef struct {
    uint8 port_name : 4;
    uint8 pin : 3;
    uint8 led_status : 1; 
}led_t;

/* Section : Function Declerations */
Std_ReturnType led_intialize(const led_t *led);
Std_ReturnType led_turn_on(const led_t *led);
Std_ReturnType led_turn_off(const led_t *led);
Std_ReturnType led_turn_toggle(const led_t *led);

#endif	/* LED_H */

