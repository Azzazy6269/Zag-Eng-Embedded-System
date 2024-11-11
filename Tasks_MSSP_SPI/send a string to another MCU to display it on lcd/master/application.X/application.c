/* 
 * File:   application.c
 * Author: moham
 *
 * Created on April 22, 2024, 5:52 AM
 */


#include "application.h"

SPI_Config spi_obj;
char message[] = "I am MCU1";
uint8 rec_data;

int main() {
    Std_ReturnType ret = E_NOT_OK;
    spi_obj.spi_config.SampleSelect = SPI_DATA_SAMPLE_MIDDLE;
    spi_obj.spi_config.ClockSelect = SPI_TRANSMIT_IDLE_TO_ACTIVE;
    spi_obj.spi_config.ClockPolarity = SPI_IDLE_STATE_LOW_LEVEL;
    spi_obj.spi_mode = SPI_MASTER_FOSC_DIV4;
    
    // Initialize the SPI module
    SPI_Init(&spi_obj);
    __delay_ms(500);  // Give time for the slave to initialize its SPI module

     const uint8_t message[] = "I am MCU1";
    SPI_Send_String(&spi_obj, message);
    
    while (1) {
        // Master loop (optional additional code if needed)
    }

    return (EXIT_SUCCESS);
}


void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK ;
}



    