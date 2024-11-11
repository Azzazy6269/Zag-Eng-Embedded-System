/* 
 * File:   usart.h
 * Author: smart
 *
 * Created on 16 SEP, 2024, 06:39 ?
 */

#ifndef USART_H
#define	USART_H

/* ---------------Section : Includes----------------- */
#include "../GPIO/hal_gpio.h"
#include "../Interrupt/Internal_interrupt.h"
#include "../mcal_std_types.h"
#include "usart_cfg.h"

/* ----------------Section : MACRO Declerations---------------- */
/* EUSART Module Enable */
#define EUSART_MODULE_ENABLE 1
#define EUSART_MODULE_DISABLE 0
/* Selecting EUSART Working Mode */
#define EUSART_SYNCHRONOUS_MODE   1
#define EUSART_ASYNCHRONOUS_MODE  0
/* Baud Rate Generator Asynchronous Speed Mode */
#define EUSART_ASYNCHRONOUS_HIGH_SPEED  1
#define EUSART_ASYNCHRONOUS_LOW_SPEED  0
/* Baud Rate Generator Register Size */
#define EUSART_16BIT_BAUDRATE_GEN      1
#define EUSART_08BIT_BAUDRATE_GEN      0
/* EUSART Transmit Enable */
#define EUSART_ASYNCHRONOUS_TX_ENABLE    1
#define EUSART_ASYNCHRONOUS_TX_DISABLE   0
/* EUSART Transmit Interrupt Enable */
#define EUSART_ASYNCHRONOUS_INTERRUPT_TX_ENABLE    1
#define EUSART_ASYNCHRONOUS_INTERRUPT_TX_DISABLE   0
/* EUSART 9-Bit Transmit Enable */
#define EUSART_ASYNCHRONOUS_9BIT_TX_ENABLE    1
#define EUSART_ASYNCHRONOUS_9BIT_TX_DISABLE   0
/* EUSART Receiver Enable */
#define EUSART_ASYNCHRONOUS_RX_ENABLE    1
#define EUSART_ASYNCHRONOUS_RX_DISABLE   0
/* EUSART Recevier Enable */
#define EUSART_ASYNCHRONOUS_INTERRUPT_RX_ENABLE    1
#define EUSART_ASYNCHRONOUS_INTERRUPT_RX_DISABLE   0
/* EUSART 9-Bit Receive Enable */
#define EUSART_ASYNCHRONOUS_9BIT_RX_ENABLE    1
#define EUSART_ASYNCHRONOUS_9BIT_RX_DISABLE   0
/* EUSART Framing Error */
#define EUSART_FRAMING_ERROR_DETECTED   1
#define EUSART_FRAMING_ERROR_CLEARED    0
/* EUSART Overrun Error */
#define EUSART_OVERRUN_ERROR_DETECTED   1
#define EUSART_OVERRUN_ERROR_CLEARED    0

/* ----------------Section : MACRO Functions Declerations------------------ */



/* ----------------Section : Data Types Declerations-------------- */
typedef enum{
    BAUDRATE_ASYN_8BIT_LOW_SPEED,
    BAUDRATE_ASYN_8BIT_HIGH_SPEED,
    BAUDRATE_ASYN_16BIT_LOW_SPEED,
    BAUDRATE_ASYN_16BIT_HIGH_SPEED,
    BAUDRATE_SYN_8BIT,
    BAUDRATE_SYN_16BIT
}baudrate_gen_t;

typedef struct{
    uint8 usart_tx_reversed : 5;
    uint8 usart_tx_enable : 1;
    uint8 usart_tx_interrupt_enable :1;
    uint8 usart_tx_9bit_enable :1;
#if EUSART_TX_INTERRUPT_FEATURE_ENABLE     ==     FEATURE_ENABLE
    void (*EUSART_TxDefaultInterruptHandler)(void);
#if INTERRUPT_PRIORITY_LEVELS_ENABLE  ==   FEATURE_ENABLE
    interrupt_priority_cfg TX_priority ;
#endif
#endif
}usart_tx_cfg_t;

typedef struct{
    uint8 usart_rx_reversed : 5;
    uint8 usart_rx_enable : 1;
    uint8 usart_rx_interrupt_enable :1;
    uint8 usart_rx_9bit_enable :1;
#if EUSART_RX_INTERRUPT_FEATURE_ENABLE     ==     FEATURE_ENABLE
    void (*EUSART_RxDefaultInterruptHandler)(void);
#if INTERRUPT_PRIORITY_LEVELS_ENABLE  ==   FEATURE_ENABLE
    interrupt_priority_cfg RX_priority ;
#endif
#endif
}usart_rx_cfg_t;

typedef union{
    struct{
        uint8 usart_tx_reversed : 6;
        uint8 usart_ferr : 1;
        uint8 usart_oerr : 1;
    };
    uint8 status;
}usart_error_status_t;

typedef struct {
    uint32 baudrate;
    baudrate_gen_t baudrate_gen_config;
    usart_tx_cfg_t usart_tx_cfg;
    usart_rx_cfg_t usart_rx_cfg;
    usart_error_status_t error_status;
    void (*EUSART_framingErrorHandler)(void);
    void (*EUSART_OverrunErrorHandler)(void);
}usart_t;
/* ------------------Section : Function Declerations---------------- */
Std_ReturnType EUSART_ASYNC_Init(const usart_t *_eusart);
Std_ReturnType EUSART_ASYNC_DeInit(const usart_t *_eusart);
Std_ReturnType EUSART_ASYNC_ReadByteBlocking(uint8 *_data);
Std_ReturnType EUSART_ASYNC_ReadByteNonBlocking(uint8 *_data);
Std_ReturnType EUSART_ASYNC_WriteByteBlocking(uint8 _data);
Std_ReturnType EUSART_ASYNC_WriteStringBlocking(uint8 *_data ,uint16 str_length);
Std_ReturnType EUSART_ASYNC_WriteByteNonBlocking(uint8 _data);
Std_ReturnType EUSART_ASYNC_WriteStringNonBlocking(uint8 *_data ,uint16 str_length);
Std_ReturnType EUSART_ASYNC_Rx_Restart(void);
#endif	/* USART_H */

