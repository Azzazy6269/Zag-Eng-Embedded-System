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
#include "ECU_Layer/ECU_layer_intialize.h"
#include "MCAL_Layer/Interrupt/External_interrupt.h"
/* Section : MACRO Declerations */


/* Section : MACRO Functions Declerations */


/* Section : Data Types Declerations */

/* Section : Function Declerations */
void application_intialize();
void Int0_APP_ISR(void);
void Int1_APP_ISR(void);
void Int2_APP_ISR(void);


#endif	/* APPLICATION_H */

