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
uint8 keypad_value;




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
    usart_obj.usart_tx_cfg.EUSART_TxDefaultInterruptHandler = NULL;
    usart_obj.EUSART_framingErrorHandler = NULL;
    
    application_intialize(); 
    EUSART_ASYNC_Init(&usart_obj);
    
    while(1){
    ret = keypad_get_value(&keypad1,&keypad_value);
    EUSART_ASYNC_WriteByteBlocking(keypad_value);

    }
    return (EXIT_SUCCESS);

}


void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK ;
    ret = keypad_intialize(&keypad1);
}



    