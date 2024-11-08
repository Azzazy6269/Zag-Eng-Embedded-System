/* 
 * File:   Interrupt_config.h
 * Author: smart
 *
 * Created on 25 , 7 , 2024, 02:26 ?
 */

#ifndef INTERRUPT_CONFIG_H
#define	INTERRUPT_CONFIG_H

/* Section : Includes */
#include "../mcal_std_types.h"
#include "../GPIO/hal_gpio.h"
#include "Interrupt_gen_cfg.h"


/* Section : MACRO Declerations */
#define INTERRUPT_ENABLE           1
#define INTERRUPT_DISABLE          0
#define INTERRUPT_OCCUR            1
#define INTERRUPT_NOT_OCCUR        0
#define INTERRUPT_PRIORITY_ENABLE  1
#define INTERRUPT_PRIORITY_DISABLE 0


/* Section : MACRO Functions Declerations */


#if INTERRUPT_PRIORITY_LEVELS_ENABLE == FEATURE_ENABLE

/*This Macro will enable priority levels*/
#define INTERRUPT_PriorityLevelsEnable()        (RCONbits.IPEN = 1)
/*This Macro will disable priority levels*/
#define INTERRUPT_PriorityLevelsEnDisable()     (RCONbits.IPEN = 0)

/*This Macro will enable high priority Global Interrupts*/
#define INTERRUPT_GlobalInturreptHighEnable()   (INTCONbits.GIEH = 1)
/*This Macro will disable high priority Global Interrupts*/
#define INTERRUPT_GlobalInturreptHighDisable()  (INTCONbits.GIEH = 0)

/*This Macro will enable low priority Global Interrupts*/
#define INTERRUPT_GlobalInturreptLowEnable()    (INTCONbits.GIEL = 1)
/*This Macro will disable low priority Global Interrupts*/
#define INTERRUPT_GlobalInturreptLowDisable()   (INTCONbits.GIEL = 0)

#else
/*This Macro will enable Global Interrupts*/
#define INTERRUPT_GlobalInturreptEnable()       (INTCONbits.GIE = 1)
/*This Macro will disable Global Interrupts*/
#define INTERRUPT_GlobalInturreptDisable()      (INTCONbits.GIE = 0)

/* This Macro will enable Peripheral Interrupts*/
#define INTERRUPT_PeripheralInterruptEnable()   (INTCONbits.PEIE = 1)
/* This Macro will disable Peripheral Interrupts*/
#define INTERRUPT_PeripheralInterruptDisable()  (INTCONbits.PEIE = 0)

#endif



/* Section : Data Types Declerations */
typedef enum{
   INTERRUPT_LOW_PRIORITY =0,
   INTERRUPT_HIGH_PRIORITY
}interrupt_priority_cfg;

/* Section : Function Declerations */

#endif	/* INTERRUPT_CONFIG_H */

