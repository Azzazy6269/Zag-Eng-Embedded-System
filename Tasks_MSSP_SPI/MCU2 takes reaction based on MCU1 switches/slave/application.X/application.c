/* 
 * File:   application.c
 * Author: moham
 *
 * Created on April 22, 2024, 5:52 AM
 */


#include "application.h"


SPI_Config spi_obj;
pin_config_t SlaveSelect;
uint8 rec_data;
int main() {
    Std_ReturnType ret = E_NOT_OK ;
    application_intialize();
    spi_obj.spi_config.SampleSelect=SPI_DATA_SAMPLE_MIDDLE;
    spi_obj.spi_config.ClockSelect =SPI_TRANSMIT_IDLE_TO_ACTIVE;
    spi_obj.spi_config.ClockPolarity =SPI_IDLE_STATE_LOW_LEVEL;
    spi_obj.spi_mode =SPI_SLAVE_SS_DISABLE;
    SPI_Init(&spi_obj);
    //SPI_Send_Byte(&spi_obj,'f');
    SPI_Read_Byte(&spi_obj,&rec_data);
    while(1){
    SPI_Read_Byte(&spi_obj,&rec_data);
    if (rec_data == 'a'){
        led_turn_on(&led1);
    }else if(rec_data == 'b'){
        led_turn_off(&led1);
    }
    if (rec_data == 'c'){
        led_turn_on(&led2);
    }else if(rec_data == 'd'){
        led_turn_off(&led2);
    }
        }
    
    return (EXIT_SUCCESS);

}


void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK ;
    led_intialize(&led1);
    led_intialize(&led2);
    
}



    