/* 
 * File:   Internal_interrupt.h
 * Author: smart
 *
 * Created on 25 , 7 , 2024, 01:57 ?
 */

#ifndef INTERNAL_INTERRUPT_H
#define	INTERNAL_INTERRUPT_H

/* Section : Includes */
#include "Interrupt_config.h"

/* Section : MACRO Declerations */
#if ADC_INTERRUPT_FEATURE_ENABLE         ==    FEATURE_ENABLE
/* This Routine clears the interrupt enable for the ADC Module */
#define ADC_InterruptDisable()        (PIE1bits.ADIE = 0)
/* This Routine Set the interrupt enable for the ADC Module */
#define ADC_InterruptEnable()         (PIE1bits.ADIE = 1)
/* This Routine clears the interrupt flag for the ADC Module */
#define ADC_InterruptFlagClear()        (PIR1bits.ADIF = 0)
#if INTERRUPT_PRIORITY_LEVELS_ENABLE      ==    FEATURE_ENABLE
/* This Routine set High priority for the ADC Module */
#define ADC_HighPrioritySet()        (IPR1bits.ADIP = 1)
/* This Routine set Low priority for the ADC Module */
#define ADC_LowPrioritySet()         (IPR1bits.ADIP = 0)
#endif

#endif

/* Section : MACRO Functions Declerations */


/* Section : Data Types Declerations */


/* Section : Function Declerations */


#endif	/* INTERNAL_INTERRUPT_H */
