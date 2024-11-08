/* 
 * File:   application.h
 * Author: moham
 *
 * Created on April 22, 2024, 6:23 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

/* Section : Includes */
#include "ECU_Layer/led/led.h"
#include "MCAL_Layer/device_config.h"
#include "ECU_Layer/DC_motor/DC_motor.h"

/* Section : MACRO Declerations */


/* Section : MACRO Functions Declerations */


/* Section : Data Types Declerations */
void Go_Forward(void);
void Go_Backward(void);
void Turn_Right(void);
void Turn_Left(void);
dc_motor_t dc_motor_1;
dc_motor_t dc_motor_2;

/* Section : Function Declerations */
void application_intialize();

#endif	/* APPLICATION_H */

