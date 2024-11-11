/* 
 * File:   application.c
 * Author: moham
 *
 * Created on April 22, 2024, 5:52 AM
 */


#include "application.h"


SPI_Config spi_obj;
uint8 rec_data;
int main() {
    Std_ReturnType ret = E_NOT_OK ;
    spi_obj.spi_config.SampleSelect=SPI_DATA_SAMPLE_MIDDLE;
    spi_obj.spi_config.ClockSelect =SPI_TRANSMIT_IDLE_TO_ACTIVE;
    spi_obj.spi_config.ClockPolarity =SPI_IDLE_STATE_LOW_LEVEL;
    spi_obj.spi_mode =SPI_MASTER_FOSC_DIV4;
    SPI_Init(&spi_obj);
        __delay_ms(100);  //to give the receiver the time it needs to intialize SPI module and be ready to act with the transmitter well
     
    SPI_Send_Byte(&spi_obj,'h');
    SPI_Read_Byte(&spi_obj,rec_data);
    while(1){
        }
    
    return (EXIT_SUCCESS);

}


void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK ;
}



    