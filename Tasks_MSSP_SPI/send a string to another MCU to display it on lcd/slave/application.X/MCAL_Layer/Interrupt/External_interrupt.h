/* 
 * File:   External_interrupt.h
 * Author: smart
 *
 * Created on 25 , 7 , 2024, 01:56 ?
 */

#ifndef EXTERNAL_INTERRUPT_H
#define	EXTERNAL_INTERRUPT_H

/* Section : Includes */
#include "interrupt_config.h"

/* Section : MACRO Declerations */
#if EXTERNAL_INTERRUPT_INTx_FEATURE_ENABLE == FEATURE_ENABLE
/*This routine sets the interrupt enable for the external interrupt, INT0 */
#define EXT_INT0_InterruptEnable()          (INTCONbits.INT0E = 1)
/*This routine clear the interrupt enable for the external interrupt, INT0 */
#define EXT_INT0_InterruptDisable()         (INTCONbits.INT0E = 0)
/*This routine clear the interrupt flag for the external interrupt, INT0 */
#define EXT_INT0_InterruptFlagClear()       (INTCONbits.INT0IF = 0)
/*This routine set the edge detect of the extern Interrupt to negative edge */
#define EXT_INT0_RisingEdgeSet()            (INTCON2bits.INTEDG0 =1)
/*This routine set the edge detect of the extern Interrupt to positive edge */
#define EXT_INT0_FallingEdgeSet()           (INTCON2bits.INTEDG0 =0)

/*This routine sets the interrupt enable for the external interrupt, INT1 */
#define EXT_INT1_InterruptEnable()          (INTCON3bits.INT1IE = 1)
/*This routine clear the interrupt enable for the external interrupt, INT1 */
#define EXT_INT1_InterruptDisable()         (INTCON3bits.INT1IE = 0)
/*This routine clear the interrupt flag for the external interrupt, INT1 */
#define EXT_INT1_InterruptFlagClear()       (INTCON3bits.INT1IF = 0)
/*This routine set the edge detect of the extern Interrupt to negative edge */
#define EXT_INT1_RisingEdgeSet()            (INTCON2bits.INTEDG1 =1)
/*This routine set the edge detect of the extern Interrupt to positive edge */
#define EXT_INT1_FallingEdgeSet()           (INTCON2bits.INTEDG1 =0)

/*This routine sets the interrupt enable for the external interrupt, INT2 */
#define EXT_INT2_InterruptEnable()          (INTCON3bits.INT2IE = 1)
/*This routine clear the interrupt enable for the external interrupt, INT2 */
#define EXT_INT2_InterruptDisable()         (INTCON3bits.INT2IE = 0)
/*This routine clear the interrupt flag for the external interrupt*/
#define EXT_INT2_InterruptFlagClear()       (INTCON3bits.INT2IF = 0)
/*This routine set the edge detect of the extern Interrupt to negative edge */
#define EXT_INT2_RisingEdgeSet()            (INTCON2bits.INTEDG2 =1)
/*This routine set the edge detect of the extern Interrupt to positive edge */
#define EXT_INT2_FallingEdgeSet()           (INTCON2bits.INTEDG2 =0)


#if INTERRUPT_PRIORITY_LEVELS_ENABLE  == FEATURE_ENABLE
/*This routine set the INT1 to be high priority*/
#define EXT_INT1_HighPrioritySet()     (INTCON3bits.INT1IP = 1)
/*This routine set the INT1 to be low priority*/
#define EXT_INT1_LowPrioritySet()     (INTCON3bits.INT1IP = 0)
/*This routine set the INT2 to be high priority*/
#define EXT_INT2_HighPrioritySet()     (INTCON3bits.INT2IP = 1)
/*This routine set the INT2 to be low priority*/
#define EXT_INT2_LowPrioritySet()     (INTCON3bits.INT2IP = 0)
/*NOTE*********INT0 Priority is Fixed*/
#endif 
#endif

#if EXTERNAL_INTERRUPT_OnChange_FEATURE_ENABLE == FEATURE_ENABLE
/*This routine set the Interrupt Enable for the external interrupt, RBx */
#define EXT_RBx_InterruptEnable()          (INTCONbits.RBIE = 1)
/*This routine clear the Interrupt Enable for the external interrupt, RBx */
#define EXT_RBx_InterruptDisable()         (INTCONbits.RBIE = 0)
/*This routine set the Interrupt Flag for the external interrupt, RBx */
#define EXT_RBx_InterruptFlagClear()       (INTCONbits.RBIF = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == FEATURE_ENABLE
/*This routine set the RBx External Interrupt Priority to be High priority*/
#define EXT_RBx_Priority_High()             (INTCON2bits.RBIP = 1)
/*This routine set the RBx External Interrupt Priority to be Low Priority*/
#define EXT_RBx_Priority_Low()              (INTCON2bits.RBIP = 0)
#endif

#endif



//#endif
/* Section : MACRO Functions Declerations */


/* Section : Data Types Declerations */
typedef enum{
     INTERRUPT_FALLING_EDGE =0,
     INTERRUPT_RISING_EDGE
}interrupt_INTx_edge;
typedef enum{
    INTERRUPT_EXTERNAL_INT0 = 0,
    INTERRUPT_EXTERNAL_INT1,
    INTERRUPT_EXTERNAL_INT2
}interrupt_INTx_src;

typedef struct{
    void (* EXT_InterruptHandler)(void);
    pin_config_t           mcu_pin;
    interrupt_INTx_edge    edge;
    interrupt_INTx_src     source;
    interrupt_priority_cfg priority;
}interrupt_INTx_t;

typedef struct{
    void (* EXT_InterruptHandlerHigh)(void);
    void (* EXT_InterruptHandlerLow)(void);
    pin_config_t           mcu_pin;
    interrupt_priority_cfg priority;

}interrupt_RBx_t;

/* Section : Function Declerations */
Std_ReturnType Interrupt_INTx_Init  (const interrupt_INTx_t *int_obj);
Std_ReturnType Interrupt_INTx_DeInit(const interrupt_INTx_t *int_obj);
Std_ReturnType Interrupt_RBx_Init   (const interrupt_RBx_t *int_obj);
Std_ReturnType Interrupt_RBx_DeInit (const interrupt_RBx_t *int_obj);







#endif	/* EXTERNAL_INTERRUPT_H */

