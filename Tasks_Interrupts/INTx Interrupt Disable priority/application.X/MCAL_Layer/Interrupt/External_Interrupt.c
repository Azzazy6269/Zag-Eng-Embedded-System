/* 
 * File:   External_interrupt.c
 * Author: smart
 *
 * Created on 25 , 7 , 2024, 01:56 ?
 */

#include "External_interrupt.h"


static void (*INT0_InterruptHandler) (void) = NULL;
static void (*INT1_InterruptHandler) (void) = NULL;
static void (*INT2_InterruptHandler) (void) = NULL;

static Std_ReturnType Interrupt_INTx_Enable(const interrupt_INTx_t * int_obj);
static Std_ReturnType Interrupt_INTx_Disable(const interrupt_INTx_t * int_obj);
static Std_ReturnType Interrupt_INTx_Priority_Init(const interrupt_INTx_t * int_obj);
static Std_ReturnType Interrupt_INTx_Edge_Init(const interrupt_INTx_t * int_obj);
static Std_ReturnType Interrupt_INTx_Pin_Init(const interrupt_INTx_t * int_obj);
static Std_ReturnType Interrupt_INTx_Clear_Flag(const interrupt_INTx_t * int_obj);

static Std_ReturnType INT0_SetInterruptHandler(void (*InterruptHandler)(void));
static Std_ReturnType INT1_SetInterruptHandler(void (*InterruptHandler)(void));
static Std_ReturnType INT2_SetInterruptHandler(void (*InterruptHandler)(void));
static Std_ReturnType Interrupt_INTx_SetInterruptHandler(const interrupt_INTx_t * int_obj);


static Std_ReturnType Interrupt_RBx_Enable(const interrupt_RBx_t * int_obj);
static Std_ReturnType Interrupt_RBx_Disable(const interrupt_RBx_t * int_obj);
static Std_ReturnType Interrupt_RBx_Priority_Init(const interrupt_RBx_t * int_obj);
static Std_ReturnType Interrupt_RBx_Pin_Init(const interrupt_RBx_t * int_obj);



/**
 * 
 * @param int_obj
 * @return 
 */
Std_ReturnType Interrupt_INTx_Init  (const interrupt_INTx_t *int_obj){
   Std_ReturnType ret = E_OK;
   if(NULL == int_obj){
       ret = E_NOT_OK;
   }else{
       /* Disable the External interrupt */
       ret = Interrupt_INTx_Disable(int_obj);
       /* Clear Interrupt Flag : External interrupt did not occur */
       ret = Interrupt_INTx_Clear_Flag(int_obj);
       /*Configure External interrupt edge */
       ret = Interrupt_INTx_Edge_Init(int_obj);
       #if INTERRUPT_PRIORITY_LEVELS_ENABLE      ==      FEATURE_ENABLE
       /* Configure External interrupt priority */
       ret = Interrupt_INTx_Priority_Init(int_obj);
       #endif
       /* Configure External interrupt I/O pin */
       ret = Interrupt_INTx_Pin_Init(int_obj);
       /* Configure Default Interrupt CallBack */
       ret = Interrupt_INTx_SetInterruptHandler(int_obj);
       /* Enable the External interrupt */
       ret = Interrupt_INTx_Enable(int_obj);
   }
   return ret;
}
/**
 * 
 * @param int_obj
 * @return 
 */
Std_ReturnType Interrupt_INTx_DeInit(const interrupt_INTx_t *int_obj){
  Std_ReturnType ret = E_OK;
   if(NULL == int_obj){
       ret = E_NOT_OK;
   }else{
       ret = Interrupt_INTx_Disable(&(int_obj));
   }
   return ret;  
}
/**
 * 
 * @param int_obj
 * @return 
 */
Std_ReturnType Interrupt_RBx_Init   (const interrupt_RBx_t *int_obj){
 Std_ReturnType ret = E_OK;
   if(NULL == int_obj){
       ret = E_NOT_OK;
   }else{
       
   }
   return ret;   
}
/**
 * 
 * @param int_obj
 * @return 
 */
Std_ReturnType Interrupt_RBx_DeInit (const interrupt_RBx_t *int_obj){
    Std_ReturnType ret = E_OK;
   if(NULL == int_obj){
       ret = E_NOT_OK;
   }else{
       
   }
   return ret;
}






static Std_ReturnType Interrupt_INTx_Enable(const interrupt_INTx_t * int_obj){
 Std_ReturnType ret = E_OK;
   if(NULL == int_obj){
       ret = E_NOT_OK;
   }else{
       switch (int_obj->source){
           case   INTERRUPT_EXTERNAL_INT0 :
               INTERRUPT_GlobalInturreptEnable();
               INTERRUPT_PeripheralInterruptEnable();
               EXT_INT0_InterruptEnable() ;
               break ;
           case   INTERRUPT_EXTERNAL_INT1 :
               INTERRUPT_GlobalInturreptEnable();
               INTERRUPT_PeripheralInterruptEnable();
               EXT_INT1_InterruptEnable() ;
               break ;
           case   INTERRUPT_EXTERNAL_INT2 :
               INTERRUPT_GlobalInturreptEnable();
               INTERRUPT_PeripheralInterruptEnable();
               EXT_INT2_InterruptEnable() ;
               break ;
           default : ret = E_NOT_OK;
       }
   }
   return ret;   
}
static Std_ReturnType Interrupt_INTx_Disable(const interrupt_INTx_t * int_obj){
   Std_ReturnType ret = E_OK;
   if(NULL == int_obj){
       ret = E_NOT_OK;
   }else{
       switch (int_obj->source){
           case   INTERRUPT_EXTERNAL_INT0 : EXT_INT0_InterruptDisable() ; break ;
           case   INTERRUPT_EXTERNAL_INT1 : EXT_INT1_InterruptDisable() ; break ;
           case   INTERRUPT_EXTERNAL_INT2 : EXT_INT2_InterruptDisable() ; break ;
   }
   return ret; 
   }
}
#if INTERRUPT_PRIORITY_LEVELS_ENABLE  == FEATURE_ENABLE
static Std_ReturnType Interrupt_INTx_Priority_Init(const interrupt_INTx_t * int_obj){
    Std_ReturnType ret = E_OK;
   if(NULL == int_obj){
       ret = E_NOT_OK;
   }else{
       switch (int_obj->source){
           case   INTERRUPT_EXTERNAL_INT1 : 
               if(int_obj->priority == INTERRUPT_LOW_PRIORITY){EXT_INT1_LowPrioritySet();}
               else if(int_obj->priority == INTERRUPT_HIGH_PRIORITY){EXT_INT1_HighPrioritySet();}
               else{/*nothing*/};
               break ;
           
           case   INTERRUPT_EXTERNAL_INT2 : 
               if(int_obj->priority == INTERRUPT_LOW_PRIORITY){EXT_INT2_LowPrioritySet();}
               else if(int_obj->priority == INTERRUPT_HIGH_PRIORITY){EXT_INT2_HighPrioritySet();}
               else{/*nothing*/};
               break ;
   }
   return ret;
}
}
#endif
static Std_ReturnType Interrupt_INTx_Edge_Init(const interrupt_INTx_t * int_obj){
    Std_ReturnType ret = E_OK;
   if(NULL == int_obj){
       ret = E_NOT_OK;
   }else{
       switch (int_obj->source){
           case   INTERRUPT_EXTERNAL_INT0 : 
               if(int_obj->edge == INTERRUPT_FALLING_EDGE){EXT_INT0_FallingEdgeSet();}
               else if(int_obj->edge == INTERRUPT_RISING_EDGE){EXT_INT0_RisingEdgeSet();}
               else{/*nothing*/};
               break ;
           case   INTERRUPT_EXTERNAL_INT1 : 
               if(int_obj->edge == INTERRUPT_FALLING_EDGE){EXT_INT1_FallingEdgeSet();}
               else if(int_obj->edge == INTERRUPT_RISING_EDGE){EXT_INT1_RisingEdgeSet();}
               else{/*nothing*/};
               break ;
           
           case   INTERRUPT_EXTERNAL_INT2 : 
               if(int_obj->edge == INTERRUPT_FALLING_EDGE){EXT_INT2_FallingEdgeSet();}
               else if(int_obj->edge == INTERRUPT_RISING_EDGE){EXT_INT2_RisingEdgeSet();}
               else{/*nothing*/};
               break ;
   }
   }
   return ret;
}
static Std_ReturnType Interrupt_INTx_Pin_Init(const interrupt_INTx_t * int_obj){
    Std_ReturnType ret = E_OK;
   if(NULL == int_obj){
       ret = E_NOT_OK;
   }else{
       ret = gpio_pin_direction_intialize(&(int_obj->mcu_pin));
   }
   return ret;
}
static Std_ReturnType Interrupt_INTx_Clear_Flag(const interrupt_INTx_t * int_obj){
    Std_ReturnType ret = E_OK;
   if(NULL == int_obj){
       ret = E_NOT_OK;
   }else{
       switch (int_obj->source){
           case   INTERRUPT_EXTERNAL_INT0 : EXT_INT0_InterruptFlagClear() ; break ;
           case   INTERRUPT_EXTERNAL_INT1 : EXT_INT1_InterruptFlagClear() ; break ;
           case   INTERRUPT_EXTERNAL_INT2 : EXT_INT2_InterruptFlagClear() ; break ;
           default : ret = E_NOT_OK;
   }
   }
   return ret;  
}


static Std_ReturnType INT0_SetInterruptHandler(void (*InterruptHandler)(void)){
    Std_ReturnType ret = E_OK;
   if(NULL == InterruptHandler){
       ret = E_NOT_OK;
   }else{
       INT0_InterruptHandler = InterruptHandler;
   }
   return ret; 
}
static Std_ReturnType INT1_SetInterruptHandler(void (*InterruptHandler)(void)){
    Std_ReturnType ret = E_OK;
   if(NULL == InterruptHandler){
       ret = E_NOT_OK;
   }else{
       INT1_InterruptHandler = InterruptHandler;
   }
   return ret; 
}
static Std_ReturnType INT2_SetInterruptHandler(void (*InterruptHandler)(void)){
     Std_ReturnType ret = E_OK;
   if(NULL == InterruptHandler){
       ret = E_NOT_OK;
   }else{
       INT2_InterruptHandler = InterruptHandler;
   }
   return ret;
}
static Std_ReturnType Interrupt_INTx_SetInterruptHandler(const interrupt_INTx_t * int_obj){
    Std_ReturnType ret = E_OK;
   if(NULL == int_obj){
       ret = E_NOT_OK;
   }else{
       switch (int_obj->source){
           case   INTERRUPT_EXTERNAL_INT0 : INT0_SetInterruptHandler(int_obj->EXT_InterruptHandler) ; break ;
           case   INTERRUPT_EXTERNAL_INT1 : INT1_SetInterruptHandler(int_obj->EXT_InterruptHandler) ; break ;
           case   INTERRUPT_EXTERNAL_INT2 : INT2_SetInterruptHandler(int_obj->EXT_InterruptHandler) ; break ;
           default : ret = E_NOT_OK;
       }
   }
}



void INT0_ISR(void){
    /* The INT0 external interrupt occured ( must be cleared in software )*/
    EXT_INT0_InterruptFlagClear();
    /* Code */
    
    /* Callback function gets called every time this ISR executes */
    if(INT0_InterruptHandler){ INT0_InterruptHandler(); }
}
void INT1_ISR(void){
    /* The INT1 external interrupt occured ( must be cleared in software )*/
    EXT_INT1_InterruptFlagClear();
    /* Code */
    
    /* Callback function gets called every time this ISR executes */
    if(INT1_InterruptHandler){ INT1_InterruptHandler(); }
}
void INT2_ISR(void){
    /* The IN20 external interrupt occured ( must be cleared in software )*/
    EXT_INT2_InterruptFlagClear();
    /* Code */
    
    /* Callback function gets called every time this ISR executes */
    if(INT2_InterruptHandler){ INT2_InterruptHandler(); }
}