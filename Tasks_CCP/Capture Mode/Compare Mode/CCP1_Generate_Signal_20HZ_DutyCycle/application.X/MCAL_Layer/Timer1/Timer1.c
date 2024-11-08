/* 
 * File:   Timer1.c
 * Author: smart
 *
 * Created on 22 Aug, 2024, 01:00 ?
 */

#include "Timer1.h"

#if TIMER1_INTERRUPT_FEATURE_ENABLE   ==  FEATURE_ENABLE
static  void (* TMR1_InterruptHandler)(void)=NULL;
#endif

static uint16 timer1_preload =ZERO_INIT;

static inline void Timer1_Mode_select(const timer1_t *_timer);


Std_ReturnType Timer1_Init(const timer1_t * _timer){
    Std_ReturnType ret = E_OK;
    if(NULL == _timer){
       ret = E_NOT_OK; 
    }
    else{
    TIMER1_MODULE_DISABLE();
    TIMER_PRESCALER_SELECT(_timer->prescaler_value);
    Timer1_Mode_select(_timer);
    TMR1H = (_timer->timer1_preload_value)>>8;
    TMR1L = (uint8)(_timer->timer1_preload_value);
    timer1_preload = _timer->timer1_preload_value;
#if TIMER1_INTERRUPT_FEATURE_ENABLE      ==     FEATURE_ENABLE
        TIMER1_InterruptEnable();
        TIMER1_InterruptFlagClear();
        TMR1_InterruptHandler =_timer ->TMR1_InterruptHandler ;
#if INTERRUPT_PRIORITY_LEVELS_ENABLE  ==   FEATURE_ENABLE
        INTERRUPT_PriorityLevelsEnable();
        if(INTERRUPT_HIGH_PRIORITY == _timer ->priority){
            TIMER1_HighPrioritySet();
            INTERRUPT_GlobalInturreptHighEnable();
        }
        else if(INTERRUPT_LOW_PRIORITY ==_timer->priority){
            TIMER1_LowPrioritySet();
            INTERRUPT_GlobalInturreptLowEnable();
        }
#else        
        INTERRUPT_GlobalInturreptEnable();
        INTERRUPT_PeripheralInterruptEnable();
#endif
#endif
    TIMER1_MODULE_ENABLE();
    
    }
    return ret;
}
Std_ReturnType Timer1_DeInit(const timer1_t * _timer){
   Std_ReturnType ret = E_OK;
    if(NULL == _timer){
       ret = E_NOT_OK; 
    }
    else{
    TIMER1_MODULE_DISABLE();
    #if INTERRUPT_PRIORITY_LEVELS_ENABLE  ==   FEATURE_ENABLE
    TIMER1_InterruptDisable();
    #endif
    }
    return ret; 
}
Std_ReturnType Timer1_Write_value(const timer1_t * _timer,uint16 _value){
    Std_ReturnType ret = E_OK;
    if(NULL == _timer){
       ret = E_NOT_OK; 
    }
    else{
    TMR1H = (_value)>>8;
    TMR1L = (uint8)(_value);  
    }
    return ret;
}
Std_ReturnType Timer1_Read_value(const timer1_t * _timer,uint16 *_value){
    Std_ReturnType ret = E_OK;
    uint8 l_tmr1l = ZERO_INIT,l_tmr1h = ZERO_INIT;
    if((NULL == _timer) || (NULL == _value)){
       ret = E_NOT_OK; 
    }
    else{
     l_tmr1l = TMR1L;   
     l_tmr1h = TMR1H;
     *_value = (uint16)((l_tmr1h << 8) + l_tmr1l);
    }
    return ret;
}


static inline void Timer1_Mode_select(const timer1_t *_timer){
    if(TIMER1_TIMER_MODE == _timer->timer1_mode ){
        TIMER1_TIMER_MODE_ENABLE();
    }
    else if(TIMER1_COUNTER_MODE == _timer->timer1_mode ){
        TIMER1_COUNTER_MODE_ENABLE();
        if(TIMER1_ASYNC_COUNTER_MODE == _timer->timer1_counter_mode){TIMER1_ASYNC_COUNTER_MODE_ENABLE();} 
        else if(TIMER1_SYNC_COUNTER_MODE == _timer->timer1_counter_mode){TIMER1_SYNC_COUNTER_MODE_ENABLE();}
        else{/*Nothing*/}
    }
    else {/*Nothing*/}
}


#if TIMER1_INTERRUPT_FEATURE_ENABLE   ==  FEATURE_ENABLE
void TMR1_ISR(void){
    TIMER1_InterruptFlagClear();
    TMR1H = (timer1_preload) >> 8;
    TMR1L = (uint8)(timer1_preload);
    if(TMR1_InterruptHandler){
        TMR1_InterruptHandler();
    }
    
}
#endif