/* 
 * File:   application.h
 * Author: moham
 *
 * Created on April 22, 2024, 6:23 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

/* Section : Includes */
#include "MCAL_Layer/device_config.h"
#include "MCAL_Layer/mcal_std_types.h"
#include "ECU_Layer/ECU_layer_intialize.h"
/* Section : MACRO Declerations */


/* Section : MACRO Functions Declerations */


/* Section : Data Types Declerations */
extern chr_lcd_8bits_t lcd2;
extern chr_lcd_4bits_t lcd1;

/* Section : Function Declerations */
void application_intialize();

#endif	/* APPLICATION_H */

