/* 
 * File:   adc_cfg.h
 * Author: smart
 *
 * Created on 13 Aug, 2024, 01:06 ?
 */

#include "adc.h"

static inline void adc_input_channel_pin_configure(adc_channel_select_t channel);
static inline void select_result_format(const adc_conf_t *_adc);
static inline void configure_voltage_reference(const adc_conf_t *_adc);



/**
 * @Summary Initializes the ADC
 * @Description This routine initialize the ADC
 *              This routine must be called before any other ADC routine is called
 *              This routine should only be called once during system initialization 
 * @param _adc Pointer to the ADC Configurations
 * @return Status of the function
 *         E_OK  : The function done successfully
 *         E_NOT_OK  : The function has issue to perform this action
 */
Std_ReturnType ADC_Init(const adc_conf_t * _adc){
    Std_ReturnType ret =E_OK ;
    if(NULL == _adc){
        ret = E_NOT_OK;
    }else{
        /* Disable the ADC */
        ADC_CONVERTER_DISABLE();
        /* Configure the acquisition time */
        ADCON2bits.ACQT=_adc->acquisition_time;
        /* Configure the conversion clock */
        ADCON2bits.ADCS=_adc->conversion_clock;
        /* Configure the default channel */
        ADCON0bits.CHS=_adc ->adc_channel;
        adc_input_channel_pin_configure(_adc->adc_channel);
        /* Configure the interrupt */
#if ADC_INTERRUPT_FEATURE_ENABLE ==1
        
#endif
        /* Configure the result format */
        select_result_format(_adc);
        /* select the voltage reference */
        configure_voltage_reference(_adc);
        /* Enable the ADC */
        ADC_CONVERTER_ENABLE();
    }
    return ret ;
}

/**
 * @Summary DeInitializes the ADC 
 * @param _adc Pointer to the ADC Configurations
 * @return Status of the function
 *         E_OK  : The function done successfully
 *         E_NOT_OK  : The function has issue to perform this action
 */
Std_ReturnType ADC_DeInit(const adc_conf_t*_adc){
    Std_ReturnType ret =E_OK ;
    if(NULL == _adc){
        ret = E_NOT_OK;
    }else{
        /* Disable the ADC */
        ADC_CONVERTER_DISABLE();
        /* Disable the interrupt */
        
    }
    return ret ;
}

/**
 * @Summary select channel of the ADC 
 * @param _adc Pointer to the ADC Configurations
 * @return Status of the function
 *         E_OK  : The function done successfully
 *         E_NOT_OK  : The function has issue to perform this action
 */
Std_ReturnType ADC_SelectChannel(const adc_conf_t * _adc,adc_channel_select_t channel){
    Std_ReturnType ret =E_OK ;
    if(NULL == _adc){
        ret = E_NOT_OK;
    }else{
        ADCON0bits.CHS=channel;
        adc_input_channel_pin_configure(channel);
    }
    return ret ;
    /* NOTE : there is no need to use _adc because there is one adc in pic18f4620 
     *        but if you have more than one adc you should use switch loop to detect which adc is used ..... you will use _adc */
}

/**
 * @Summary Start Conversion 
 * @param _adc Pointer to the ADC Configurations
 * @return Status of the function
 *         E_OK  : The function done successfully
 *         E_NOT_OK  : The function has issue to perform this action
 */
Std_ReturnType ADC_StartConversion(const adc_conf_t * _adc){
    Std_ReturnType ret =E_OK ;
    if(NULL == _adc){
        ret = E_NOT_OK;
    }else{
        ADC_START_CONVERSION();
    }
    return ret ;
}

/**
 * @Summary True if conversion done / False if conversion not done
 * @param _adc Pointer to the ADC Configurations , Conversion_Status
 * @return Status of the function
 *         E_OK  : The function done successfully
 *         E_NOT_OK  : The function has issue to perform this action
 */
Std_ReturnType ADC_IsConversionDone(const adc_conf_t * _adc,uint8 *Conversion_status){
    Std_ReturnType ret =E_OK ;
    if(NULL == _adc || NULL==Conversion_status){
        ret = E_NOT_OK;
    }else{
       *Conversion_status= (uint8)(!(ADCON0bits.GO_nDONE));
    }
    return ret ;
}

/**
 * @Summary Get the Result of the conversion  
 * @param _adc Pointer to the ADC Configurations
 * @return Status of the function
 *         E_OK  : The function done successfully
 *         E_NOT_OK  : The function has issue to perform this action
 */
Std_ReturnType ADC_GetConversionResult(const adc_conf_t * _adc,uint16 * Conversion_result){
    Std_ReturnType ret =E_OK ;
    if(NULL == _adc  ||  NULL==Conversion_result){
        ret = E_NOT_OK;
    }else{
       if(ADC_RESULT_RIGHT == _adc->result_format){
          *Conversion_result = (uint16)((ADRESH << 8 )+ ADRESL) ;
       }
       else if(ADC_RESULT_LEFT==_adc->result_format){
          *Conversion_result = (uint16)(((ADRESH << 8 )+ ADRESL)>>6)   ;
       }  
    }
    return ret ;
}

Std_ReturnType ADC_GetConversion_Blocking(const adc_conf_t * _adc,uint16 *Conversion_result,adc_channel_select_t channel){
  Std_ReturnType ret = E_NOT_OK;
  uint8 l_conversion_status = ZERO_INIT;
  if((NULL == _adc) ||  (NULL == Conversion_result)){
      ret = E_NOT_OK;
  }
  else{
      /* select the A/D channel */
      ret = ADC_SelectChannel(_adc,channel);
      /* Start the conversion */
      ret = ADC_StartConversion(_adc);
      /* Check if conversion is completed */
      while(ADCON0bits.GO_DONE);
      ret = ADC_GetConversionResult(_adc,Conversion_result);
  }
  return ret;
}




static inline void adc_input_channel_pin_configure(adc_channel_select_t channel){
    switch(channel){
        case ADC_CHANNEL_AN0  : SET_BIT(TRISA,_TRISA_TRISA0_POSN);break;
        case ADC_CHANNEL_AN1  : SET_BIT(TRISA,_TRISA_TRISA1_POSN);break;
        case ADC_CHANNEL_AN2  : SET_BIT(TRISA,_TRISA_TRISA2_POSN);break;
        case ADC_CHANNEL_AN3  : SET_BIT(TRISA,_TRISA_TRISA3_POSN);break;
        case ADC_CHANNEL_AN4  : SET_BIT(TRISA,_TRISA_TRISA5_POSN);break;
        case ADC_CHANNEL_AN5  : SET_BIT(TRISE,_TRISE_TRISE0_POSN);break;
        case ADC_CHANNEL_AN6  : SET_BIT(TRISE,_TRISE_TRISE1_POSN);break;
        case ADC_CHANNEL_AN7  : SET_BIT(TRISE,_TRISE_TRISE2_POSN);break;
        case ADC_CHANNEL_AN8  : SET_BIT(TRISB,_TRISB_TRISB2_POSN);break;
        case ADC_CHANNEL_AN9  : SET_BIT(TRISB,_TRISB_TRISB3_POSN);break;
        case ADC_CHANNEL_AN10 : SET_BIT(TRISB,_TRISB_TRISB1_POSN);break;
        case ADC_CHANNEL_AN11 : SET_BIT(TRISB,_TRISB_TRISB4_POSN);break;
        case ADC_CHANNEL_AN12 : SET_BIT(TRISB,_TRISB_TRISB0_POSN);break;
    }
}


static inline void select_result_format(const adc_conf_t *_adc){
    if(ADC_RESULT_RIGHT == _adc->result_format){
        ADC_RESULT_RIGHT_FORMAT();
    }
    else if(ADC_RESULT_LEFT==_adc->result_format){
        ADC_RESULT_LEFT_FORMAT();
    }
}


static inline void configure_voltage_reference(const adc_conf_t *_adc){
    if(ADC_VOLTAGE_REFERENCE_ENABLED==_adc->voltage_reference){
        ADC_ENABLE_VOLTAGE_REFRENCE();
    }
    else if(ADC_VOLTAGE_REFERENCE_DISABLED==_adc->voltage_reference){
        ADC_DISABLE_VOLTAGE_REFRENCE();
    }
}
