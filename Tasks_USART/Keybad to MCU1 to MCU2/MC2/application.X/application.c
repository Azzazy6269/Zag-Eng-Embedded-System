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
uint8 a1=0;uint8 a2=0;uint8 a3=0;

void EUSART_RxDefaultInterruptHandler(){
    if(rec_uart_data=='1'){led_turn_on(&led1);}
    else if (rec_uart_data=='2'){led_turn_on(&led2);}
    else if (rec_uart_data=='3'){led_turn_on(&led3);}
}

int main() {
    Std_ReturnType ret=E_NOT_OK;
    usart_obj.baudrate =9600;
    usart_obj.baudrate_gen_config =BAUDRATE_ASYN_16BIT_LOW_SPEED;
    
    usart_obj.usart_tx_cfg.usart_tx_enable= EUSART_ASYNCHRONOUS_TX_ENABLE;
    usart_obj.usart_tx_cfg.usart_tx_interrupt_enable = EUSART_ASYNCHRONOUS_INTERRUPT_TX_DISABLE;
    usart_obj.usart_tx_cfg.usart_tx_9bit_enable = EUSART_ASYNCHRONOUS_9BIT_TX_DISABLE;
    
    usart_obj.usart_rx_cfg.usart_rx_enable= EUSART_ASYNCHRONOUS_RX_ENABLE;
    usart_obj.usart_rx_cfg.usart_rx_interrupt_enable = EUSART_ASYNCHRONOUS_INTERRUPT_RX_DISABLE;
    usart_obj.usart_rx_cfg.usart_rx_9bit_enable = EUSART_ASYNCHRONOUS_9BIT_RX_DISABLE;
    
    usart_obj.EUSART_OverrunErrorHandler = NULL;
    usart_obj.usart_rx_cfg.EUSART_RxDefaultInterruptHandler = EUSART_RxDefaultInterruptHandler;
   // usart_obj.EUSART_TxDefaultInterruptHandler = NULL;
    usart_obj.EUSART_framingErrorHandler = NULL;
    
    EUSART_ASYNC_Init(&usart_obj);
    application_intialize(); 
    
    while(1){
    EUSART_ASYNC_ReadByteBlocking(&rec_uart_data);
         if (rec_uart_data=='1'){led_turn_on(&led1);}
    else if (rec_uart_data=='2'){led_turn_on(&led2);}
    else if (rec_uart_data=='3'){led_turn_on(&led3);}
    
    }
    return (EXIT_SUCCESS);
}


void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK ;
    ret = led_intialize(&led1);
    ret = led_intialize(&led2);
    ret = led_intialize(&led3);
}



    