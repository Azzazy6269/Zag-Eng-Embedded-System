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
#include "MCAL_Layer/I2C/I2C.h"
#include "MCAL_Layer/SPI/spi.h"
/* Section : MACRO Declerations */


/* Section : MACRO Functions Declerations */


/* Section : Data Types Declerations */
extern chr_lcd_8bits_t lcd2;
extern chr_lcd_4bits_t lcd1;
/* Section : Function Declerations */
void MSSP_I2C_DefaultInterruptHandler(void);
void MSSP_SPI_DefaultInterruptHandler(void);




#endif	/* APPLICATION_H */

