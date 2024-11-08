/* 
 * File:   adc.h
 * Author: smart
 *
 * Created on 13 Aug, 2024, 01:00 ?
 */

#ifndef ADC_H
#define	ADC_H

/* Section : Includes */
#include "../mcal_std_types.h"
#include "C:\Program Files\Microchip\MPLABX\v6.20\packs\Microchip\PIC18Fxxxx_DFP\1.6.159\xc8\pic\include\proc\pic18f4620.h"
#include "../GPIO/hal_gpio.h"
#include "adc_cfg.h"
#include "../Interrupt/Internal_interrupt.h"
/* Section : MACRO Declerations */
#define ADC_AN0_ANALOG_FUNCTIONALITY    0x0E
#define ADC_AN0_ANALOG_FUNCTIONALITY    0x0D
#define ADC_AN0_ANALOG_FUNCTIONALITY    0x0C
#define ADC_AN0_ANALOG_FUNCTIONALITY    0x0B
#define ADC_AN0_ANALOG_FUNCTIONALITY    0x0A
#define ADC_AN0_ANALOG_FUNCTIONALITY    0x09
#define ADC_AN0_ANALOG_FUNCTIONALITY    0x08
#define ADC_AN0_ANALOG_FUNCTIONALITY    0x07
#define ADC_AN0_ANALOG_FUNCTIONALITY    0x06
#define ADC_AN0_ANALOG_FUNCTIONALITY    0x05
#define ADC_AN0_ANALOG_FUNCTIONALITY    0x04
#define ADC_AN0_ANALOG_FUNCTIONALITY    0x03
#define ADC_AN0_ANALOG_FUNCTIONALITY    0x02
#define ADC_ALL_ANALOG_FUNCTIONALITY    0x00
#define ADC_ALL_DIGITAL_FUNCTIONALITY   0x0F


#define ADC_RESULT_RIGHT 0x01U
#define ADC_RESULT_LEFT 0x00U


#define ADC_VOLTAGE_REFERENCE_ENABLED     0x01U
#define ADC_VOLTAGE_REFERENCE_DISABLED     0x00U



 /* Section : MACRO Functions Declerations */
/* A/D Conversion Status : A/D Conversion in progress */
#define ADC_CONVERSION_STATUS()    (ADCON0bits.GO_nDONE)
#define ADC_START_CONVERSION()     (ADCON0bits.GO_nDONE =1)
/* A/D Conversion Enable/Disable */
#define ADC_CONVERTER_ENABLE()     (ADCON0bits.ADON =1)
#define ADC_CONVERTER_DISABLE()    (ADCON0bits.ADON =0)
/** ADC_ENABLE_VOLTAGE_REFRENCE()  :   voltage ref is Vref-(AN2)  & Vref+(AN3)  
    ADC_ENABLE_VOLTAGE_REFRENCE()  :   voltage ref is Vref-(VSS)  & Vref+(VDD)   */
#define ADC_ENABLE_VOLTAGE_REFRENCE()  do{ADCON1bits.VCFG1=1;\
                                          ADCON1bits.VCFG0=1;\
                                         }while(0)
#define ADC_DISABLE_VOLTAGE_REFRENCE()  do{ADCON1bits.VCFG1=0;\
                                          ADCON1bits.VCFG0=0;\
                                         }while(0)
/* Analog-To-Digital port Configuration control */
#define ADC_ANALOG_DIGITAL_PORT_CONFIG(_CONFIG) (ADCON1bits.PCFG=_CONFIG)
/*A/D Result Format Select */
#define ADC_RESULT_RIGHT_FORMAT()   (ADCON2bits.ADFM=1)
#define ADC_RESULT_LEFT_FORMAT()   (ADCON2bits.ADFM=0)

/* Section : Data Types Declerations */
typedef enum {
    ADC_CHANNEL_AN0=0,
    ADC_CHANNEL_AN1,
    ADC_CHANNEL_AN2,
    ADC_CHANNEL_AN3,
    ADC_CHANNEL_AN4,
    ADC_CHANNEL_AN5,
    ADC_CHANNEL_AN6,
    ADC_CHANNEL_AN7,
    ADC_CHANNEL_AN8,
    ADC_CHANNEL_AN9,
    ADC_CHANNEL_AN10,
    ADC_CHANNEL_AN11,
    ADC_CHANNEL_AN12, 
}adc_channel_select_t;

typedef enum{
    ADC_0_TAD =0,
    ADC_2_TAD,
    ADC_4_TAD,
    ADC_6_TAD,
    ADC_8_TAD,
    ADC_12_TAD,
    ADC_16_TAD,
    ADC_20_TAD,
}adc_acquisition_time_t;

typedef enum{
   ADC_CONVERSION_CLOCK_FOSC_DIV_2 =0,
   ADC_CONVERSION_CLOCK_FOSC_DIV_8,
   ADC_CONVERSION_CLOCK_FOSC_DIV_32,
   ADC_CONVERSION_CLOCK_FOSC_DIV_FRC,
   ADC_CONVERSION_CLOCK_FOSC_DIV_4,
   ADC_CONVERSION_CLOCK_FOSC_DIV_16,
   ADC_CONVERSION_CLOCK_FOSC_DIV_64,
}adc_conversion_clock_t;

typedef struct{
#if ADC_INTERRUPT_FEATURE_ENABLE   ==  FEATURE_ENABLE
    void (* ADC_InterruptHandler)(void);
    interrupt_priority_cfg priority ;
#endif
    adc_acquisition_time_t acquisition_time;
    adc_conversion_clock_t conversion_clock;
    adc_channel_select_t adc_channel;
    uint8 voltage_reference : 1;
    uint8 result_format : 1;
    uint8 ADC_Reserved : 6;
}adc_conf_t;
/* Section : Function Declerations */
Std_ReturnType ADC_Init(const adc_conf_t * _adc);
Std_ReturnType ADC_DeInit(const adc_conf_t*_adc);
Std_ReturnType ADC_SelectChannel(const adc_conf_t * _adc,adc_channel_select_t channel);
Std_ReturnType ADC_StartConversion(const adc_conf_t * _adc);
Std_ReturnType ADC_IsConversionDone(const adc_conf_t * _adc,uint8 *Conversion_status);
Std_ReturnType ADC_GetConversionResult(const adc_conf_t * _adc,uint16 *Conversion_result);
Std_ReturnType ADC_GetConversion_Blocking(const adc_conf_t * _adc,uint16 *Conversion_result,adc_channel_select_t channel) ;


/*The user will use ADC_Init function at the beginning of his application 
 * Then he will use ADC_GetConversion_Blocking function at any time ...he do not usually need to use other functions in this header file in his application */

#endif	/* ADC_H */

