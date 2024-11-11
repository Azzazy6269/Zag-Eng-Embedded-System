/* 
 * File:   Timer3.c
 * Author: smart
 *
 * Created on 23 Aug, 2024, 10:55 ?
 */

#include "Timer3.h"

#if TIMER3_INTERRUPT_FEATURE_ENABLE   ==  FEATURE_ENABLE
static  void (* TMR3_InterruptHandler)(void)=NULL;
#endif

static uint16 timer3_preload =ZERO_INIT;

static inline void Timer3_Mode_select(const timer3_t *_timer);


Std_ReturnType Timer3_Init(const timer3_t * _timer){
    Std_ReturnType ret = E_OK;
    if(NULL == _timer){
       ret = E_NOT_OK; 
    }
    else{
    TIMER3_MODULE_DISABLE();
    TIMER_PRESCALER_SELECT(_timer->timer3_prescaler_value);
    Timer3_Mode_select(_timer);
    TMR3H = (_timer->timer3_preload_value)>>8;
    TMR3L = (uint8)(_timer->timer3_preload_value);
    timer3_preload = _timer->timer3_preload_value;
#if TIMER3_INTERRUPT_FEATURE_ENABLE      ==     FEATURE_ENABLE
        TIMER3_InterruptEnable();
        TIMER3_InterruptFlagClear();
        TMR3_InterruptHandler =_timer ->TMR3_InterruptHandler ;
#if INTERRUPT_PRIORITY_LEVELS_ENABLE  ==   FEATURE_ENABLE
        INTERRUPT_PriorityLevelsEnable();
        if(INTERRUPT_HIGH_PRIORITY == _timer ->priority){
            TIMER3_HighPrioritySet();
            INTERRUPT_GlobalInturreptHighEnable();
        }
        else if(INTERRUPT_LOW_PRIORITY ==_timer->priority){
            TIMER3_LowPrioritySet();
            INTERRUPT_GlobalInturreptLowEnable();
        }
#else        
        INTERRUPT_GlobalInturreptEnable();
        INTERRUPT_PeripheralInterruptEnable();
#endif
#endif
    TIMER3_MODULE_ENABLE();
    
    }
    return ret;
}
Std_ReturnType Timer3_DeInit(const timer3_t * _timer){
    Std_ReturnType ret = E_OK;
    if(NULL == _timer){
       ret = E_NOT_OK; 
    }
    else{
    TIMER3_MODULE_DISABLE();
    #if INTERRUPT_PRIORITY_LEVELS_ENABLE  ==   FEATURE_ENABLE
    TIMER3_InterruptDisable();
    #endif
    }
    return ret;
}
Std_ReturnType Timer3_Write_value(const timer3_t * _timer,uint16 _value){
    Std_ReturnType ret = E_OK;
    if(NULL == _timer){
       ret = E_NOT_OK; 
    }
    else{
    TMR3H = (_value)>>8;
    TMR3L = (uint8)(_value); 
    }
    return ret;
}
Std_ReturnType Timer3_Read_value(const timer3_t * _timer,uint16 *_value){
    Std_ReturnType ret = E_OK;
    uint8 l_tmr3l = ZERO_INIT,l_tmr3h = ZERO_INIT;
    if((NULL == _timer) || (NULL == _value)){
       ret = E_NOT_OK; 
    }
    else{
     l_tmr3l = TMR3L;   
     l_tmr3h = TMR3H;
     *_value = (uint16)((l_tmr3h << 8) + l_tmr3l);
    }
    return ret;
}


static inline void Timer3_Mode_select(const timer3_t *_timer){
     if(TIMER3_TIMER_MODE == _timer->timer3_mode ){
        TIMER3_TIMER_MODE_ENABLE();
    }
    else if(TIMER3_COUNTER_MODE == _timer->timer3_mode ){
        TIMER3_COUNTER_MODE_ENABLE();
        if(TIMER3_ASYNC_COUNTER_MODE == _timer->timer3_counter_mode){TIMER3_ASYNC_COUNTER_MODE_ENABLE();} 
        else if(TIMER3_SYNC_COUNTER_MODE == _timer->timer3_counter_mode){TIMER3_SYNC_COUNTER_MODE_ENABLE();}
        else{/*Nothing*/}
    }
    else {/*Nothing*/}
}


#if TIMER3_INTERRUPT_FEATURE_ENABLE   ==  FEATURE_ENABLE
void TMR3_ISR(void){
    TIMER3_InterruptFlagClear();
    TMR3H = (timer3_preload) >> 8;
    TMR3L = (uint8)(timer3_preload);
    if(TMR3_InterruptHandler){
        TMR3_InterruptHandler();
    }
    
}
#endif