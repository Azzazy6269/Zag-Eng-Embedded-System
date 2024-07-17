/* 
 * File:   ECU_layer_intialize.h
 * Author: moham
 *
 * Created on May 12, 2024, 2:33 AM
 */

#ifndef ECU_LAYER_INTIALIZE_H
#define	ECU_LAYER_INTIALIZE_H

/* Section : Includes */
#include "led/led.h"
#include "button/button.h"
#include "relay/relay.h"
#include "DC_motor/DC_motor.h"
#include "7segment/seven_seg.h"
#include "Keypad/keypad.h"
#include "lcd/lcd.h"
#include "button/button.h"

/* Section : MACRO Declerations */



 


/* Section : MACRO Functions Declerations */


/* Section : Data Types Declerations */
button_t button ;
button_t switch__ ;
dc_motor_t dc_motor_1;
/* Section : Function Declerations */
void application_intialize();

#endif	/* ECU_LAYER_INTIALIZE_H */

