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

#if TIMER0_INTERRUPT_FEATURE_ENABLE         ==    FEATURE_ENABLE
/* This Routine clears the interrupt enable for the Timer0 Module */
#define TIMER0_InterruptDisable()        (INTCONbits.TMR0IE = 0)
/* This Routine Set the interrupt enable for the Timer0 Module */
#define TIMER0_InterruptEnable()         (INTCONbits.TMR0IE = 1)
/* This Routine clears the interrupt flag for the Timer0 Module */
#define TIMER0_InterruptFlagClear()      (INTCONbits.TMR0IF= 0)
#if INTERRUPT_PRIORITY_LEVELS_ENABLE      ==    FEATURE_ENABLE
/* This Routine set High priority for the TIMER0 Module */
#define TIMER0_HighPrioritySet()        (INTCON2bits.TMR0IP = 1)
/* This Routine set Low priority for the TIMER0 Module */
#define TIMER0_LowPrioritySet()         (INTCON2bits.TMR0IP = 0)
#endif
#endif


#if TIMER1_INTERRUPT_FEATURE_ENABLE         ==    FEATURE_ENABLE
/* This Routine clears the interrupt enable for the Timer1 Module */
#define TIMER1_InterruptDisable()        (PIE1bits.TMR1IE = 0)
/* This Routine Set the interrupt enable for the Timer1 Module */
#define TIMER1_InterruptEnable()         (PIE1bits.TMR1IE = 1)
/* This Routine clears the interrupt flag for the Timer1 Module */
#define TIMER1_InterruptFlagClear()      (PIR1bits.TMR1IF = 0)
#if INTERRUPT_PRIORITY_LEVELS_ENABLE      ==    FEATURE_ENABLE
/* This Routine set High priority for the TIMER1 Module */
#define TIMER1_HighPrioritySet()        (IPR1bits.TMR1IP = 1)
/* This Routine set Low priority for the TIMER1 Module */
#define TIMER1_LowPrioritySet()         (IPR1bits.TMR1IP = 0)
#endif
#endif


#if TIMER2_INTERRUPT_FEATURE_ENABLE         ==    FEATURE_ENABLE
/* This Routine clears the interrupt enable for the Timer2 Module */
#define TIMER2_InterruptDisable()        (PIE1bits.TMR2IE = 0)
/* This Routine Set the interrupt enable for the Timer2 Module */
#define TIMER2_InterruptEnable()         (PIE1bits.TMR2IE = 1)
/* This Routine clears the interrupt flag for the Timer2 Module */
#define TIMER2_InterruptFlagClear()      (PIR1bits.TMR2IF = 0)
#if INTERRUPT_PRIORITY_LEVELS_ENABLE      ==    FEATURE_ENABLE
/* This Routine set High priority for the TIMER2 Module */
#define TIMER2_HighPrioritySet()        (IPR1bits.TMR2IP =1)
/* This Routine set Low priority for the TIMER2 Module */
#define TIMER2_LowPrioritySet()         (IPR1bits.TMR2IP = 0)
#endif
#endif


#if TIMER3_INTERRUPT_FEATURE_ENABLE         ==    FEATURE_ENABLE
/* This Routine clears the interrupt enable for the Timer3 Module */
#define TIMER3_InterruptDisable()        (PIE2bits.TMR3IE = 0)
/* This Routine Set the interrupt enable for the Timer3 Module */
#define TIMER3_InterruptEnable()         (PIE2bits.TMR3IE = 1)
/* This Routine clears the interrupt flag for the Timer3 Module */
#define TIMER3_InterruptFlagClear()      (PIR2bits.TMR3IF =0)
#if INTERRUPT_PRIORITY_LEVELS_ENABLE      ==    FEATURE_ENABLE
/* This Routine set High priority for the TIMER3 Module */
#define TIMER3_HighPrioritySet()        (IPR2bits.TMR3IP =1)
/* This Routine set Low priority for the TIMER3 Module */
#define TIMER3_LowPrioritySet()         (IPR2bits.TMR3IP)
#endif
#endif


#if CCP1_INTERRUPT_FEATURE_ENABLE         ==    FEATURE_ENABLE
/* This Routine clears the interrupt enable for the CCP1 Module */
#define CCP1_InterruptDisable()        (PIE1bits.CCP1IE =0)
/* This Routine Set the interrupt enable for the CCP1 Module */
#define CCP1_InterruptEnable()         (PIE1bits.CCP1IE =1)
/* This Routine clears the interrupt flag for the CCP1 Module */
#define CCP1_InterruptFlagClear()      (PIR1bits.CCP1IF = 0)
#if INTERRUPT_PRIORITY_LEVELS_ENABLE      ==    FEATURE_ENABLE
/* This Routine set High priority for the CCP1 Module */
#define CCP1_HighPrioritySet()        (IPR1bits.CCP1IP = 1)
/* This Routine set Low priority for the CCP1 Module */
#define CCP1_LowPrioritySet()         (IPR1bits.CCP1IP = 0)
#endif
#endif

#if CCP2_INTERRUPT_FEATURE_ENABLE         ==    FEATURE_ENABLE
/* This Routine clears the interrupt enable for the CCP2 Module */
#define CCP2_InterruptDisable()        (PIE2bits.CCP2IE =0)
/* This Routine Set the interrupt enable for the CCP2 Module */
#define CCP2_InterruptEnable()         (PIE2bits.CCP2IE =1)
/* This Routine clears the interrupt flag for the CCP2 Module */
#define CCP2_InterruptFlagClear()      (PIR2bits.CCP2IF = 0)
#if INTERRUPT_PRIORITY_LEVELS_ENABLE      ==    FEATURE_ENABLE
/* This Routine set High priority for the CCP2 Module */
#define CCP2_HighPrioritySet()        (IPR2bits.CCP2IP = 1)
/* This Routine set Low priority for the CCP2 Module */
#define CCP2_LowPrioritySet()         (IPR2bits.CCP2IP = 0)
#endif
#endif
/* Section : MACRO Functions Declerations */


/* Section : Data Types Declerations */


/* Section : Function Declerations */


#endif	/* INTERNAL_INTERRUPT_H */

