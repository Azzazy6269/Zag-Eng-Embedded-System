/* 
 * File:   Interrupt_manager.h
 * Author: smart
 *
 * Created on 25 , 7 , 2024, 01:53 ?
 */

#ifndef INTERRUPT_MANAGER_H
#define	INTERRUPT_MANAGER_H

/* Section : Includes */
#include "Interrupt_config.h"

/* Section : MACRO Declerations */


/* Section : MACRO Functions Declerations */


/* Section : Data Types Declerations */


/* Section : Function Declerations */
void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);
void RB4_ISR(uint8 RB4_source); 
void RB5_ISR(uint8 RB5_source); 
void RB6_ISR(uint8 RB6_source); 
void RB7_ISR(uint8 RB7_source); 
void ADC_ISR(void);
void TMR0_ISR(void);
void TMR1_ISR(void);
void TMR2_ISR(void);
void TMR3_ISR(void);

#endif	/* INTERRUPT_MANAGER_H */

