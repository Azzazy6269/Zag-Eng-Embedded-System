/* 
 * File:   application.c
 * Author: moham
 *
 * Created on April 22, 2024, 5:52 AM
 */


#include "application.h"

uint16 adc_res_1=0;
volatile uint8 adc_flag =0;

adc_conf_t adc1 = {
  .ADC_InterruptHandler= ADC_DefaultInterruptHandler ,
  .acquisition_time =ADC_12_TAD, 
  .adc_channel = ADC_CHANNEL_AN0,
  .conversion_clock = ADC_CONVERSION_CLOCK_FOSC_DIV_16,
  .result_format = ADC_RESULT_RIGHT,
  .voltage_reference = ADC_VOLTAGE_REFERENCE_DISABLED
};

void ADC_DefaultInterruptHandler(void){
    adc_flag++;
    ADC_GetConversionResult(&adc1,&adc_res_1);
    if(adc_res_1<250){
        led_turn_on(&led0);led_turn_off(&led1);led_turn_off(&led2);led_turn_off(&led3);
    }else if(adc_res_1<500){
        led_turn_off(&led0);led_turn_on(&led1);led_turn_off(&led2);led_turn_off(&led3);
    }else if(adc_res_1<750){
        led_turn_off(&led0);led_turn_off(&led1);led_turn_on(&led2);led_turn_off(&led3);
    }else {
        led_turn_off(&led0);led_turn_off(&led1);led_turn_off(&led2);led_turn_on(&led3);
    }
}
int main() {
    Std_ReturnType ret=E_NOT_OK;
    application_intialize();
    while(1){
        ret = ADC_StartConversion_Interrupt(&adc1,ADC_CHANNEL_AN0);
        
    }
    return (EXIT_SUCCESS);
}




void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK ;
    ret = ADC_Init(&adc1);
    ret = led_intialize(&led0);
    ret = led_intialize(&led1);
    ret = led_intialize(&led2);
    ret = led_intialize(&led3);
    
}



    