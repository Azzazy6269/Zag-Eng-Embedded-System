/* 
 * File:   Timer2.h
 * Author: smart
 *
 * Created on 23 Aug, 2024, 05:39 ?
 */

#include "Timer2.h"

#if TIMER2_INTERRUPT_FEATURE_ENABLE   ==  FEATURE_ENABLE
static  void (* TMR2_InterruptHandler)(void)=NULL;
#endif

static uint16 timer2_preload =ZERO_INIT;


Std_ReturnType Timer2_Init(const timer2_t * _timer){
    Std_ReturnType ret = E_OK;
    if(NULL == _timer){
       ret = E_NOT_OK; 
    }
    else{
    TIMER2_MODULE_DISABLE();
    TIMER_PRESCALER_SELECT(_timer->timer2_prescaler_value);
    TIMER_POSTSCALER_SELECT(_timer->timer2_postscaler_value);
    TMR2 = _timer->timer2_preload_value;
    timer2_preload = _timer->timer2_preload_value;
    #if TIMER2_INTERRUPT_FEATURE_ENABLE      ==     FEATURE_ENABLE
        TIMER2_InterruptEnable();
        TIMER2_InterruptFlagClear();
        TMR2_InterruptHandler =_timer ->TMR2_InterruptHandler ;
#if INTERRUPT_PRIORITY_LEVELS_ENABLE  ==   FEATURE_ENABLE
        INTERRUPT_PriorityLevelsEnable();
        if(INTERRUPT_HIGH_PRIORITY == _timer ->priority){
            TIMER2_HighPrioritySet();
            INTERRUPT_GlobalInturreptHighEnable();
        }
        else if(INTERRUPT_LOW_PRIORITY ==_timer->priority){
            TIMER2_LowPrioritySet();
            INTERRUPT_GlobalInturreptLowEnable();
        }
#else        
        INTERRUPT_GlobalInturreptEnable();
        INTERRUPT_PeripheralInterruptEnable();
#endif
#endif
    TIMER2_MODULE_ENABLE();
    }
    return ret;
}
Std_ReturnType Timer2_DeInit(const timer2_t * _timer){
    Std_ReturnType ret = E_OK;
    if(NULL == _timer){
       ret = E_NOT_OK; 
    }
    else{
    TIMER2_MODULE_DISABLE();
    #if INTERRUPT_PRIORITY_LEVELS_ENABLE  ==   FEATURE_ENABLE
    TIMER2_InterruptDisable();
    #endif
    }
    return ret;
}
Std_ReturnType Timer2_Write_value(const timer2_t * _timer,uint16 _value){
    Std_ReturnType ret = E_OK;
    if(NULL == _timer){
       ret = E_NOT_OK; 
    }
    else{
        TMR2 = _value; 
    }
    return ret;
}
Std_ReturnType Timer2_Read_value(const timer2_t * _timer,uint16 *_value){
    Std_ReturnType ret = E_OK;
    if((NULL == _timer) || (NULL == _value)){
       ret = E_NOT_OK; 
    }
    else{
        *_value = TMR2;
    }
    return ret;
}


#if TIMER2_INTERRUPT_FEATURE_ENABLE   ==  FEATURE_ENABLE
void TMR2_ISR(void){
    TIMER2_InterruptFlagClear();
    TMR2 = (timer2_preload) ;
    if(TMR2_InterruptHandler){
        TMR2_InterruptHandler();
    }
    
}
#endif