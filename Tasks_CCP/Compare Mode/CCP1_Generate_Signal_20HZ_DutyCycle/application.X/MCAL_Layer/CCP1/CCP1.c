/* 
 * File:   CCP1.c
 * Author: smart
 *
 * Created on 27 Aug, 2024, 03:34 ?
 */

#include <pic18f4620.h>
#include "CCP1.h"

#if CCP1_INTERRUPT_FEATURE_ENABLE == FEATURE_ENABLE
   static void (* CCP1_InterruptHandler)(void)=NULL;
#endif

#if CCP2_INTERRUPT_FEATURE_ENABLE == FEATURE_ENABLE
   static void (* CCP2_InterruptHandler)(void)=NULL;
#endif
    
static Std_ReturnType CCP_Timer_Select(const ccp_t * _ccp_obj);
static void CCP_Interrupt_Config(const ccp_t * _ccp_obj);
static Std_ReturnType PWM_Mode_Config(const ccp_t * _ccp_obj);
static Std_ReturnType Capture_Mode_config(const ccp_t *_ccp_obj);
static Std_ReturnType Compare_Mode_config(const ccp_t * _ccp_obj);




Std_ReturnType CCP_Init(const ccp_t * _ccp_obj){
    Std_ReturnType ret = E_OK;
    if(NULL==_ccp_obj){
        ret = E_NOT_OK;
    }else{
        /* Disable Module CCP1 */
        if (_ccp_obj->ccp_inst ==CCP1_INST){
            CCP1_SET_MODE(CCP_MODULE_DISABLE);       
        }else if(_ccp_obj->ccp_inst ==CCP2_INST){
            CCP2_SET_MODE(CCP_MODULE_DISABLE);
            }else{
                ret = E_NOT_OK;}
        /* CCP1 Module Mode Initialization */
        if(CCP_CAPTURE_MODE_SELECTED == _ccp_obj->CCP_mode){
#if (CCP1_CFG_SELECTED_MODE == CCP_CFG_CAPTURE_MODE_SELECTED) || (CCP2_CFG_SELECTED_MODE == CCP_CFG_CAPTURE_MODE_SELECTED)
            ret = Capture_Mode_config(_ccp_obj);
            ret = CCP_Timer_Select(_ccp_obj);
#endif
        }
        else if(CCP_COMPARE_MODE_SELECTED == _ccp_obj->CCP_mode){
#if (CCP1_CFG_SELECTED_MODE == CCP_CFG_COMPARE_MODE_SELECTED) || (CCP2_CFG_SELECTED_MODE == CCP_CFG_COMPARE_MODE_SELECTED)
            ret = Compare_Mode_config(_ccp_obj); 
            ret = CCP_Timer_Select(_ccp_obj);
#endif            
        }
        else if(CCP_PWM_MODE_SELECTED == _ccp_obj->CCP_mode){
#if (CCP1_CFG_SELECTED_MODE == CCP_CFG_PWM_MODE_SELECTED) ||(CCP2_CFG_SELECTED_MODE == CCP_CFG_PWM_MODE_SELECTED)            
            ret = PWM_Mode_Config(_ccp_obj);
#endif            
        }     
        /* Interrupt configuration */
         CCP_Interrupt_Config(_ccp_obj);
        /* CCP pin configuration */
        ret = gpio_pin_intialize(&(_ccp_obj->ccp_pin));
    }
    return ret;
}
Std_ReturnType CCP_DeInit(const ccp_t * _ccp_obj){
    Std_ReturnType ret = E_OK;
    if(NULL==_ccp_obj){
        ret = E_NOT_OK;
    }else{
        if (_ccp_obj->ccp_inst ==CCP1_INST){
            CCP1_SET_MODE(CCP_MODULE_DISABLE);  
            #if CCP1_INTERRUPT_FEATURE_ENABLE      ==     FEATURE_ENABLE
                CCP1_InterruptDisable();
            #endif
        }else if(_ccp_obj->ccp_inst ==CCP2_INST){
            CCP2_SET_MODE(CCP_MODULE_DISABLE);
            #if CCP2_INTERRUPT_FEATURE_ENABLE      ==     FEATURE_ENABLE
                CCP2_InterruptDisable();
                #endif
            }else{
                ret = E_NOT_OK;}

    }
    return ret;
}



#if (CCP1_CFG_SELECTED_MODE == CCP_CFG_CAPTURE_MODE_SELECTED) || (CCP2_CFG_SELECTED_MODE == CCP_CFG_CAPTURE_MODE_SELECTED)
static Std_ReturnType Capture_Mode_config(const ccp_t * _ccp_obj){
    Std_ReturnType ret = E_OK;
    if (_ccp_obj->ccp_inst ==CCP1_INST){
         switch(_ccp_obj ->CCP_mode_variant){
                case CCP_CAPTURE_MODE_1_FALLING_EDGE : CCP1_SET_MODE(CCP_CAPTURE_MODE_1_FALLING_EDGE);break;
                case CCP_CAPTURE_MODE_1_RISING_EDGE : CCP1_SET_MODE(CCP_CAPTURE_MODE_1_RISING_EDGE);break;
                case CCP_CAPTURE_MODE_4_RISING_EDGE : CCP1_SET_MODE(CCP_CAPTURE_MODE_4_RISING_EDGE);break;
                case CCP_CAPTURE_MODE_16_RISING_EDGE : CCP1_SET_MODE(CCP_CAPTURE_MODE_16_RISING_EDGE);break;
                default : ret = E_NOT_OK;
            }
    }else if(_ccp_obj->ccp_inst ==CCP2_INST){
        switch(_ccp_obj ->CCP_mode_variant){
                case CCP_CAPTURE_MODE_1_FALLING_EDGE : CCP2_SET_MODE(CCP_CAPTURE_MODE_1_FALLING_EDGE);break;
                case CCP_CAPTURE_MODE_1_RISING_EDGE : CCP2_SET_MODE(CCP_CAPTURE_MODE_1_RISING_EDGE);break;
                case CCP_CAPTURE_MODE_4_RISING_EDGE : CCP2_SET_MODE(CCP_CAPTURE_MODE_4_RISING_EDGE);break;
                case CCP_CAPTURE_MODE_16_RISING_EDGE : CCP2_SET_MODE(CCP_CAPTURE_MODE_16_RISING_EDGE);break;
                default : ret = E_NOT_OK;
            }
    }else{ret = E_NOT_OK;}
    return ret ;
}
Std_ReturnType CCP_IsCapturedDataReady(const ccp_t * _ccp_obj,uint8 * _capture_status){
    Std_ReturnType ret = E_OK;
    if(NULL==_capture_status){
        ret = E_NOT_OK;
    }else{
        if (_ccp_obj->ccp_inst ==CCP1_INST){
            if(CCP_CAPTURE_READY == PIR1bits.CCP1IF){
               * _capture_status = CCP_CAPTURE_READY;
#if CCP1_INTERRUPT_FEATURE_ENABLE         ==    FEATURE_ENABLE
                CCP1_InterruptFlagClear();
#endif
            }
            else{
               * _capture_status = CCP_CAPTURE_NOT_READY;
            }    
        }else if(_ccp_obj->ccp_inst ==CCP2_INST){
            if(CCP_CAPTURE_READY == PIR2bits.CCP2IF){
               * _capture_status = CCP_CAPTURE_READY;
#if CCP2_INTERRUPT_FEATURE_ENABLE         ==    FEATURE_ENABLE
               CCP2_InterruptFlagClear();
#endif
            }
            else{
               * _capture_status = CCP_CAPTURE_NOT_READY;
            }
        }else{
                ret = E_NOT_OK;}
        
    }
    return ret;
}
Std_ReturnType CCP_Capture_Mode_Read_Value(const ccp_t * _ccp_obj,uint8 * _capture_value){
    Std_ReturnType ret = E_OK;
    CCP_REG_t capture_temp_value = {.ccpr_low=0 , .ccpr_high=0} ;
    if(NULL == _ccp_obj || NULL==_capture_value){
        ret = E_NOT_OK;
    }
    else{
        if (_ccp_obj->ccp_inst ==CCP1_INST){
            capture_temp_value.ccpr_low = CCPR1L;
            capture_temp_value.ccpr_high = CCPR1H;
           * _capture_value = capture_temp_value.ccpr_16Bit;    
        }else if(_ccp_obj->ccp_inst ==CCP2_INST){
            capture_temp_value.ccpr_low = CCPR2L;
            capture_temp_value.ccpr_high = CCPR2H;
           * _capture_value = capture_temp_value.ccpr_16Bit;
        }else{
            ret = E_NOT_OK;}
    }
    return ret;
    
}
static Std_ReturnType CCP_Capture_Mode_Timer_Select(const ccp_t * _ccp_obj){
    Std_ReturnType ret =E_OK;
    if(NULL == _ccp_obj){
        ret = E_NOT_OK;
    }
    if(CCP1_CCP2_TIMER3 == _ccp_obj ->ccp_capture_timer){
        T3CONbits.T3CCP1=0;
        T3CONbits.T3CCP2=1;
    }
    else if(CCP1_TIMER1_CCP2_TIMER3 == _ccp_obj ->ccp_capture_timer){
        T3CONbits.T3CCP1=1;
        T3CONbits.T3CCP2=0;
    }
    else if(CCP1_CCP2_TIMER1 == _ccp_obj ->ccp_capture_timer){
        T3CONbits.T3CCP1=0;
        T3CONbits.T3CCP2=0;
    }
    else{ret = E_NOT_OK;}
    return ret ;
}
#endif
#if (CCP1_CFG_SELECTED_MODE == CCP_CFG_COMPARE_MODE_SELECTED) || (CCP2_CFG_SELECTED_MODE == CCP_CFG_COMPARE_MODE_SELECTED)
static Std_ReturnType Compare_Mode_config(const ccp_t * _ccp_obj){
    Std_ReturnType ret = E_NOT_OK;
    if (_ccp_obj->ccp_inst ==CCP1_INST){
           switch(_ccp_obj ->CCP_mode_variant){
                case CCP_COMPARE_MODE_SET_PIN_LOW : CCP1_SET_MODE(CCP_COMPARE_MODE_SET_PIN_LOW);break;
                case CCP_COMPARE_MODE_SET_PIN_HIGH : CCP1_SET_MODE(CCP_COMPARE_MODE_SET_PIN_HIGH);break;
                case CCP_COMPARE_MODE_TOGGLE_ON_MATCH : CCP1_SET_MODE(CCP_COMPARE_MODE_TOGGLE_ON_MATCH);break;
                case CCP_COMPARE_MODE_GEN_SW_INTERRUPT : CCP1_SET_MODE(CCP_COMPARE_MODE_GEN_SW_INTERRUPT);break;
                case CCP_COMPARE_MODE_GEN_EVENT : CCP1_SET_MODE(CCP_COMPARE_MODE_GEN_EVENT);break;                
                default : ret = E_NOT_OK;
            }
    }else if(_ccp_obj->ccp_inst ==CCP2_INST){
        switch(_ccp_obj ->CCP_mode_variant){
                case CCP_COMPARE_MODE_SET_PIN_LOW : CCP2_SET_MODE(CCP_COMPARE_MODE_SET_PIN_LOW);break;
                case CCP_COMPARE_MODE_SET_PIN_HIGH : CCP2_SET_MODE(CCP_COMPARE_MODE_SET_PIN_HIGH);break;
                case CCP_COMPARE_MODE_TOGGLE_ON_MATCH : CCP2_SET_MODE(CCP_COMPARE_MODE_TOGGLE_ON_MATCH);break;
                case CCP_COMPARE_MODE_GEN_SW_INTERRUPT : CCP2_SET_MODE(CCP_COMPARE_MODE_GEN_SW_INTERRUPT);break;
                case CCP_COMPARE_MODE_GEN_EVENT : CCP2_SET_MODE(CCP_COMPARE_MODE_GEN_EVENT);break;                
                default : ret = E_NOT_OK;
            }
    }else{ret = E_NOT_OK;}
    return ret;
}
Std_ReturnType CCP_IsCompareComplete(const ccp_t * _ccp_obj,uint8 * _compare_status){
    Std_ReturnType ret = E_OK;
    if(NULL==_compare_status || NULL==_ccp_obj){
        ret = E_NOT_OK;
    }else{
        if (_ccp_obj->ccp_inst ==CCP1_INST){
                if(CCP_COMPARE_READY == PIR1bits.CCP1IF){
           * _compare_status = CCP_COMPARE_READY;
#if CCP1_INTERRUPT_FEATURE_ENABLE         ==    FEATURE_ENABLE
            CCP1_InterruptFlagClear();
#endif
        }
        else{
           * _compare_status = CCP_COMPARE_NOT_READY;
        }
            }else if(_ccp_obj->ccp_inst ==CCP2_INST){
                if(CCP_COMPARE_READY == PIR2bits.CCP2IF){
           * _compare_status = CCP_COMPARE_READY;
#if CCP2_INTERRUPT_FEATURE_ENABLE         ==    FEATURE_ENABLE
            CCP2_InterruptFlagClear();
#endif
        }
        else{
           * _compare_status = CCP_COMPARE_NOT_READY;
        }
            }else{
                ret = E_NOT_OK;}
        
    }
    return ret;
}
Std_ReturnType CCP_Compare_Mode_Set_Value(const ccp_t * _ccp_obj,uint16 _compare_value){
    Std_ReturnType ret = E_OK;
    if(NULL==_ccp_obj){
        ret = E_NOT_OK;
    }
    else{
        if (_ccp_obj->ccp_inst ==CCP1_INST){
            CCP_REG_t compare_temp_value = {.ccpr_low=0 , .ccpr_high=0} ;
            compare_temp_value.ccpr_16Bit = _compare_value;
            CCPR1L = compare_temp_value.ccpr_low;
            CCPR1H = compare_temp_value.ccpr_high;
        }else if(_ccp_obj->ccp_inst ==CCP2_INST){
            CCP_REG_t compare_temp_value = {.ccpr_low=0 , .ccpr_high=0} ;
            compare_temp_value.ccpr_16Bit = _compare_value;
            CCPR2L = compare_temp_value.ccpr_low;
            CCPR2H = compare_temp_value.ccpr_high; 
        }else{
                ret = E_NOT_OK;}
    }
    return ret;
}
static Std_ReturnType CCP_Timer_Select(const ccp_t * _ccp_obj){
    Std_ReturnType ret =E_OK;
    if(NULL == _ccp_obj){
        ret = E_NOT_OK;
    }
    if(CCP1_CCP2_TIMER3 == _ccp_obj ->ccp_capture_timer){
        T3CONbits.T3CCP1=0;
        T3CONbits.T3CCP2=1;
    }
    else if(CCP1_TIMER1_CCP2_TIMER3 == _ccp_obj ->ccp_capture_timer){
        T3CONbits.T3CCP1=1;
        T3CONbits.T3CCP2=0;
    }
    else if(CCP1_CCP2_TIMER1 == _ccp_obj ->ccp_capture_timer){
        T3CONbits.T3CCP1=0;
        T3CONbits.T3CCP2=0;
    }
    else{ret = E_NOT_OK;}
    return ret ;
}
#endif
#if (CCP1_CFG_SELECTED_MODE == CCP_CFG_PWM_MODE_SELECTED) || (CCP2_CFG_SELECTED_MODE == CCP_CFG_PWM_MODE_SELECTED)
static Std_ReturnType PWM_Mode_Config(const ccp_t * _ccp_obj){
    if(CCP_PWM_MODE == _ccp_obj ->CCP_mode_variant){
        if (_ccp_obj->ccp_inst ==CCP1_INST){
            CCP1_SET_MODE(CCP_PWM_MODE);
        }else if(_ccp_obj->ccp_inst ==CCP2_INST){
                CCP2_SET_MODE(CCP_PWM_MODE);
         }         
    PR2 = (uint8)((_XTAL_FREQ/4) / ((_ccp_obj->PWM_Frequency)*(_ccp_obj->timer2_prescaler_value)*(_ccp_obj->timer2_postscaler_value))-1);
         }
}
Std_ReturnType CCP_PWM_Set_Duty(const ccp_t * _ccp_obj,const uint8 _duty){
    Std_ReturnType ret = E_OK;
    uint16 l_duty_temp =0;
    if(NULL==_ccp_obj){
        ret = E_NOT_OK;
    }else{
        l_duty_temp = (uint16)(4*(PR2 +1)*(_duty / 100.0));

        if (_ccp_obj->ccp_inst ==CCP1_INST){
            CCP1CONbits.DC1B = (uint8)(l_duty_temp & 0x0003) ;
            CCPR1L = (uint8)(l_duty_temp >>2);  
        }
        else if(_ccp_obj->ccp_inst ==CCP2_INST){
            CCP2CONbits.DC2B = (uint8)(l_duty_temp & 0x0003) ;
            CCPR2L = (uint8)(l_duty_temp >>2);
        }else{
            ret = E_NOT_OK;}
    }
    return ret;
    }
Std_ReturnType CCP_PWM_Start(const ccp_t * _ccp_obj){
    Std_ReturnType ret = E_OK;
    if(NULL==_ccp_obj){
        ret = E_NOT_OK;
    }else{
        if (_ccp_obj->ccp_inst ==CCP1_INST){
            CCP1CONbits.CCP1M = CCP_PWM_MODE;
        }else if(_ccp_obj->ccp_inst ==CCP2_INST){
            CCP2CONbits.CCP2M = CCP_PWM_MODE;
        }else{
            ret = E_NOT_OK;}
    }
    return ret;
}
Std_ReturnType CCP_PWM_Stop(const ccp_t * _ccp_obj){
    Std_ReturnType ret = E_OK;
    if(NULL==_ccp_obj){
        ret = E_NOT_OK;
    }else{
        if (_ccp_obj->ccp_inst ==CCP1_INST){
            CCP1CONbits.CCP1M = CCP_MODULE_DISABLE;
        }else if(_ccp_obj->ccp_inst ==CCP2_INST){
            CCP2CONbits.CCP2M = CCP_MODULE_DISABLE;
        }else{
            ret = E_NOT_OK;}
    }
    return ret;
}
#endif


#if (CCP1_INTERRUPT_FEATURE_ENABLE == FEATURE_ENABLE) || (CCP2_INTERRUPT_FEATURE_ENABLE == FEATURE_ENABLE)
#if CCP1_INTERRUPT_FEATURE_ENABLE == FEATURE_ENABLE
void CCP1_ISR(void){
    CCP1_InterruptFlagClear();
    if(CCP1_InterruptHandler){
       CCP1_InterruptHandler();
    }
}
#endif
#if CCP2_INTERRUPT_FEATURE_ENABLE == FEATURE_ENABLE
void CCP2_ISR(void){
    CCP2_InterruptFlagClear();
    if(CCP2_InterruptHandler){
       CCP2_InterruptHandler();
    }
}
#endif
static void CCP_Interrupt_Config(const ccp_t *_ccp_obj){
/* CCP1 Interrupt Configurations */ 
#if CCP1_INTERRUPT_FEATURE_ENABLE==FEATURE_ENABLE
    CCP1_InterruptEnable();
    CCP1_InterruptFlagClear();
    CCP1_InterruptHandler = _ccp_obj->CCP1_InterruptHandler;
/* Interrupt Priority Configurations */
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==FEATURE_ENABLE 
    INTERRUPT_PriorityLevelsEnable();
    if(INTERRUPT_HIGH_PRIORITY == _ccp_obj->CCP1_priority){
        /* Enables all high-priority interrupts */
        INTERRUPT_GlobalInterruptHighEnable();
        CCP1_HighPrioritySet();
    }
    else if(INTERRUPT_LOW_PRIORITY == _ccp_obj->CCP1_priority){
        /* Enables all unmasked peripheral interrupts */
        INTERRUPT_GlobalInterruptLowEnable();
        CCP1_LowPrioritySet();
    }
    else{ /* Nothing */ }
#else
    INTERRUPT_GlobalInturreptEnable();
    INTERRUPT_PeripheralInterruptEnable();
#endif          
#endif    
        
/* CCP2 Interrupt Configurations */ 
#if CCP2_INTERRUPT_FEATURE_ENABLE==FEATURE_ENABLE
    CCP2_InterruptEnable();
    CCP2_InterruptFlagClear();
    CCP2_InterruptHandler = _ccp_obj->CCP2_InterruptHandler;
/* Interrupt Priority Configurations */
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==FEATURE_ENABLE 
    INTERRUPT_PriorityLevelsEnable();
    if(INTERRUPT_HIGH_PRIORITY == _ccp_obj->CCP2_priority){
        /* Enables all high-priority interrupts */
        INTERRUPT_GlobalInterruptHighEnable();
        CCP2_HighPrioritySet();
    }
    else if(INTERRUPT_LOW_PRIORITY == _ccp_obj->CCP2_priority){
        /* Enables all unmasked peripheral interrupts */
        INTERRUPT_GlobalInterruptLowEnable();
        CCP2_LowPrioritySet();
    }
    else{ /* Nothing */ }
#else
    INTERRUPT_GlobalInturreptEnable();
    INTERRUPT_PeripheralInterruptEnable();
#endif          
#endif 
}
#endif 


