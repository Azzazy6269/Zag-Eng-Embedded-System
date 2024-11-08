/* 
 * File:   Interrupt_manager.c
 * Author: 
 *
 * Created on 25 , 7 , 2024, 01:53 ?
 */

#include "Interrupt_manager.h"

#if INTERRUPT_PRIORITY_LEVELS_ENABLE  == FEATURE_ENABLE
void __interrupt() InterruptManagerHigh(void){

}
void __interrupt(low_priority) InterruptManagerLow(void){

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
}
#endif