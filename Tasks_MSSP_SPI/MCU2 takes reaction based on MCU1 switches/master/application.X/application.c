/* 
 * File:   application.c
 * Author: moham
 *
 * Created on April 22, 2024, 5:52 AM
 */


#include "application.h"
logic_t btn1_state;
logic_t btn2_state;
uint8 btn = 0;
SPI_Config spi_obj;
uint8 rec_data;
int main() {
    Std_ReturnType ret = E_NOT_OK ;
    application_intialize();
    spi_obj.spi_config.SampleSelect=SPI_DATA_SAMPLE_MIDDLE;
    spi_obj.spi_config.ClockSelect =SPI_TRANSMIT_IDLE_TO_ACTIVE;
    spi_obj.spi_config.ClockPolarity =SPI_IDLE_STATE_LOW_LEVEL;
    spi_obj.spi_mode =SPI_MASTER_FOSC_DIV4;
    SPI_Init(&spi_obj);
        __delay_ms(100);  //to give the receiver the time it needs to intialize SPI module and be ready to act with the transmitter well
     
    
    while(1){
        gpio_pin_read_logic(&(btn1.button_pin),&btn1_state);
      //  btn1_state = 1;
        if (btn1_state == 1){
          SPI_Send_Byte(&spi_obj,'a');
          SPI_Read_Byte(&spi_obj,rec_data);
        }else{
           SPI_Send_Byte(&spi_obj,'b');
           SPI_Read_Byte(&spi_obj,rec_data);
        }
        gpio_pin_read_logic(&(btn2.button_pin),&btn2_state);
        if (btn2_state == 1){
          SPI_Send_Byte(&spi_obj,'c');
          SPI_Read_Byte(&spi_obj,rec_data);
        }else{
           SPI_Send_Byte(&spi_obj,'d');
           SPI_Read_Byte(&spi_obj,rec_data);
        }
    }
    return (EXIT_SUCCESS);

}


void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK ;
    button_intialize(&btn1);
    button_intialize(&btn2);

    
}



    