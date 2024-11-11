/* 
 * File:   application.c
 * Author: moham
 *
 * Created on April 22, 2024, 5:52 AM
 */


#include "application.h"


usart_t usart_obj;
uint8 rec_uart_data;
uint32 y=0;

void EUSART_TxDefaultInterruptHandler(void){
    led_turn_toggle(&led1);
    __delay_ms(100);
}


int main() {
    Std_ReturnType ret=E_NOT_OK;
    usart_obj.baudrate =9600;
    usart_obj.baudrate_gen_config =BAUDRATE_ASYN_16BIT_LOW_SPEED;
    
    usart_obj.usart_tx_cfg.usart_tx_enable= EUSART_ASYNCHRONOUS_TX_ENABLE;
    usart_obj.usart_tx_cfg.usart_tx_interrupt_enable = EUSART_ASYNCHRONOUS_INTERRUPT_TX_ENABLE;
    usart_obj.usart_tx_cfg.usart_tx_9bit_enable = EUSART_ASYNCHRONOUS_9BIT_TX_DISABLE;
    
    usart_obj.usart_rx_cfg.usart_rx_enable= EUSART_ASYNCHRONOUS_RX_ENABLE;
    usart_obj.usart_rx_cfg.usart_rx_interrupt_enable = EUSART_ASYNCHRONOUS_INTERRUPT_RX_DISABLE;
    usart_obj.usart_rx_cfg.usart_rx_9bit_enable = EUSART_ASYNCHRONOUS_9BIT_RX_DISABLE;
    
    usart_obj.EUSART_OverrunErrorHandler = NULL;
    usart_obj.usart_rx_cfg.EUSART_RxDefaultInterruptHandler = NULL;
    usart_obj.usart_tx_cfg.EUSART_TxDefaultInterruptHandler = EUSART_TxDefaultInterruptHandler;
    usart_obj.EUSART_framingErrorHandler = NULL;
    
    application_intialize(); 
    EUSART_ASYNC_Init(&usart_obj);
    
    while(1){
    EUSART_ASYNC_WriteStringBlocking("Hello\r",6);

    }
    return (EXIT_SUCCESS);

}


void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK ;
    ret = led_intialize(&led1);
}



    