/* 
 * File:   application.h
 * Author: moham
 *
 * Created on April 22, 2024, 6:23 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

/* Section : Includes */
#include "MCAL_Layer/mcal_std_types.h"
#include "MCAL_Layer/device_config.h"
#include "ECU_Layer/ECU_layer_intialize.h"
#include "MCAL_Layer/Interrupt/External_interrupt.h"
#include "MCAL_Layer/EEPROM/hal_EEPROM.h"
#include "MCAL_Layer/ADC/adc.h"
#include "MCAL_Layer/Timer0/timer0.h"
#include "MCAL_Layer/Timer1/Timer1.h"
#include "MCAL_Layer/Timer2/Timer2.h"
#include "MCAL_Layer/Timer3/Timer3.h"
#include "MCAL_Layer/CCP1/CCP1.h"
#include "MCAL_Layer/USART/usart.h"
/* Section : MACRO Declerations */


/* Section : MACRO Functions Declerations */


/* Section : Data Types Declerations */

/* Section : Function Declerations */
void Timer0_DefaultInterruptHandler(void);
void Timer1_DefaultInterruptHandler(void);
void Timer2_DefaultInterruptHandler(void);
void Timer3_DefaultInterruptHandler(void);
void CCP1_DefaultInterruptHandler(void);



#endif	/* APPLICATION_H */

