/* 
 * File:   relay.h
 * Author: moham
 *
 * Created on May 7, 2024, 11:58 PM
 */

#ifndef RELAY_H
#define	RELAY_H

/* Section : Includes */
#include "ECU_relay_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/* Section : MACRO Declerations */
#define RELAY_ON_STATUS    0x01U
#define RELAY_OFF_STATUS   0x00U

/* Section : MACRO Functions Declerations */


/* Section : Data Types Declerations */
typedef struct {
    uint8 relay_port :4;
    uint8 relay_pin : 3;
    uint8 relay_status : 1;
}relay_t;

/* Section : Function Declerations */
Std_ReturnType relay_intialize(const relay_t *_relay);
Std_ReturnType relay_turn_on(const relay_t *_relay);
Std_ReturnType relay_turn_off(const relay_t *_relay);



#endif	/* RELAY_H */

