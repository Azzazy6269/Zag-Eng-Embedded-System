/* 
 * File:   application.c
 * Author: moham
 *
 * Created on April 22, 2024, 5:52 AM
 */


#include "application.h"

SPI_Config spi_obj;
char received_message[20];  // Buffer to store the received string
int index = 0;

int main() {
    Std_ReturnType ret = E_NOT_OK;
    uint8 rec_data;

    spi_obj.spi_config.SampleSelect = SPI_DATA_SAMPLE_MIDDLE;
    spi_obj.spi_config.ClockSelect = SPI_TRANSMIT_IDLE_TO_ACTIVE;
    spi_obj.spi_config.ClockPolarity = SPI_IDLE_STATE_LOW_LEVEL;
    spi_obj.spi_mode = SPI_SLAVE_SS_DISABLE;

    application_intialize();
    
    // Initialize the SPI module
    SPI_Init(&spi_obj);
    uint8 x = 5;
   SPI_Read_String(&spi_obj, received_message, sizeof(received_message));
   
    lcd_4bit_send_string_pos(&lcd1,1,7,received_message);

while (1) {

}


    return (EXIT_SUCCESS);
}

void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK ;
    ret = lcd_4bit_intialize(&lcd1);
}
