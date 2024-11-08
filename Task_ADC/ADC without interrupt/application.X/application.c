/* 
 * File:   application.c
 * Author: moham
 *
 * Created on April 22, 2024, 5:52 AM
 */


#include "application.h"

uint16 adc_res_0, adc_res_1, adc_res_2, adc_res_3;

adc_conf_t adc1 = {
  .acquisition_time =ADC_12_TAD, 
  .adc_channel = ADC_CHANNEL_AN0,
  .conversion_clock = ADC_CONVERSION_CLOCK_FOSC_DIV_16,
  .result_format = ADC_RESULT_RIGHT,
  .voltage_reference = ADC_VOLTAGE_REFERENCE_DISABLED
};
int main() {
    Std_ReturnType ret=E_NOT_OK;
    application_intialize();
    while(1){
        ret = ADC_GetConversion_Blocking(&adc1,&adc_res_0,ADC_CHANNEL_AN0);
        ret = ADC_GetConversion_Blocking(&adc1,&adc_res_1,ADC_CHANNEL_AN1);
        ret = ADC_GetConversion_Blocking(&adc1,&adc_res_2,ADC_CHANNEL_AN2);
        ret = ADC_GetConversion_Blocking(&adc1,&adc_res_3,ADC_CHANNEL_AN3);
    }
    return (EXIT_SUCCESS);
}




void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK ;
    ret = ADC_Init(&adc1);
    
    
}



    