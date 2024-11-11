/* 
 * File:   Interrupt_manager.c
 * Author: 
 *
 * Created on 25 , 7 , 2024, 01:53 ?
 */

#include "Interrupt_manager.h"

static volatile uint8 RB4_Flag = 1,RB5_Flag = 1,RB6_Flag = 1,RB7_Flag = 1;

#if INTERRUPT_PRIORITY_LEVELS_ENABLE  == FEATURE_ENABLE
void __interrupt() InterruptManagerHigh(void){
if((INTCONbits.INT0IE == INTERRUPT_ENABLE) && (INTCONbits.INT0IF == INTERRUPT_OCCUR) ){
       INT0_ISR(); 
    }else{/* Nothing */}
if((INTCON3bits.INT2IE == INTERRUPT_ENABLE) && (INTCON3bits.INT2IF == INTERRUPT_OCCUR) ){
       INT2_ISR(); 
    }else{/* Nothing */}
}
void __interrupt(low_priority) InterruptManagerLow(void){
if((INTCON3bits.INT1IE == INTERRUPT_ENABLE) && (INTCON3bits.INT1IF == INTERRUPT_OCCUR) ){
       INT1_ISR(); 
    }else{/* Nothing */}
}    
#else
void __interrupt() InterruptManager(void){
    if((INTCONbits.INT0IE == INTERRUPT_ENABLE) && (INTCONbits.INT0IF == INTERRUPT_OCCUR) ){
       INT0_ISR(); 
    }else{/* Nothing */}
    if((INTCON3bits.INT1IE == INTERRUPT_ENABLE) && (INTCON3bits.INT1IF == INTERRUPT_OCCUR) ){
       INT1_ISR(); 
    }else{/* Nothing */}
    if((INTCON3bits.INT2IE == INTERRUPT_ENABLE) && (INTCON3bits.INT2IF == INTERRUPT_OCCUR) ){
       INT2_ISR(); 
    }else{/* Nothing */}
    if((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTCONbits.RBIF == INTERRUPT_OCCUR) && (PORTBbits.RB4 == GPIO_HIGH) && (RB4_Flag == 1)){
       RB4_Flag = 0;
       RB4_ISR(1); 
    }else{/* Nothing */}
    if((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTCONbits.RBIF == INTERRUPT_OCCUR) && (PORTBbits.RB4 == GPIO_LOW) && (RB4_Flag == 0)){
        RB4_Flag = 1;
        RB4_ISR(0);
    }else{/* Nothing */}
    if((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTCONbits.RBIF == INTERRUPT_OCCUR) && (PORTBbits.RB5 == GPIO_HIGH) && (RB5_Flag == 1)){
        RB5_Flag = 0;
        RB5_ISR(1); 
    }else{/* Nothing */}
    if((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTCONbits.RBIF == INTERRUPT_OCCUR) && (PORTBbits.RB5 == GPIO_LOW) && (RB5_Flag == 0)){
        RB5_Flag = 1;
        RB5_ISR(0);
    }else{/* Nothing */}
    if((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTCONbits.RBIF == INTERRUPT_OCCUR) && (PORTBbits.RB6 == GPIO_HIGH) && (RB6_Flag == 1)){
       RB6_Flag = 0;
       RB6_ISR(1); 
    }else{/* Nothing */}
    if((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTCONbits.RBIF == INTERRUPT_OCCUR) && (PORTBbits.RB6 == GPIO_LOW) && (RB6_Flag == 0)){
        RB6_Flag = 1;
        RB6_ISR(0);
    }else{/* Nothing */}
    if((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTCONbits.RBIF == INTERRUPT_OCCUR) && (PORTBbits.RB7 == GPIO_HIGH) && (RB7_Flag == 1)){
       RB7_Flag = 0;
       RB7_ISR(1); 
    }else{/* Nothing */}
    if((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTCONbits.RBIF == INTERRUPT_OCCUR) && (PORTBbits.RB7 == GPIO_LOW) && (RB7_Flag == 0)){
       RB7_Flag = 1;
       RB7_ISR(0);
    }else{/* Nothing */}
    
    //Internal Interrupts
    
    if((PIE1bits.ADIE == INTERRUPT_ENABLE) && (PIR1bits.ADIF == INTERRUPT_OCCUR)){
        ADC_ISR();
    }else{/* Nothing */}
    if((INTCONbits.TMR0IE == INTERRUPT_ENABLE) && (INTCONbits.TMR0IF == INTERRUPT_OCCUR)){
        TMR0_ISR();
    }else{/* Nothing */}
    if((PIE1bits.TMR1IE == INTERRUPT_ENABLE) && (PIR1bits.TMR1IF == INTERRUPT_OCCUR)){
        TMR1_ISR();
    }else{/* Nothing */}
}
#endif