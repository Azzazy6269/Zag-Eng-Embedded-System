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
void RB4_APP_ISR_High(void);
void RB4_APP_ISR_Low(void);
void RB5_APP_ISR_High(void);
void RB5_APP_ISR_Low(void);
void RB6_APP_ISR_High(void);
void RB6_APP_ISR_Low(void);
void RB7_APP_ISR_High(void);
void RB7_APP_ISR_Low(void);



#endif	/* APPLICATION_H */

