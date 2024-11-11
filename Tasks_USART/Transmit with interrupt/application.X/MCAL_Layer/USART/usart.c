/* 
 * File:   usart.c
 * Author: smart
 *
 * Created on 16 SEP, 2024, 06:39 ?
 */

#include "usart.h"

#if EUSART_TX_INTERRUPT_FEATURE_ENABLE     ==     FEATURE_ENABLE
    static void (*EUSART_TxInterruptHandler)(void) = NULL;
#endif
#if EUSART_RX_INTERRUPT_FEATURE_ENABLE     ==     FEATURE_ENABLE
    static void (*EUSART_RxInterruptHandler)(void) = NULL;
    static void (*EUSART_framingErrorHandler)(void) = NULL;
    static void (*EUSART_OverrunErrorHandler)(void) = NULL;
#endif


static void EUSART_Baud_Rate_Calculation(const usart_t *_eusart);
static void EUSART_ASYNC_TX_Init(const usart_t *_eusart);
static void EUSART_ASYNC_RX_Init(const usart_t *_eusart);


Std_ReturnType EUSART_ASYNC_Init(const usart_t *_eusart){
    Std_ReturnType ret = E_OK ;
    if(NULL == _eusart){
        ret = E_NOT_OK;
    }else{
        RCSTAbits.SPEN = EUSART_MODULE_DISABLE;
        TRISCbits.RC7 = 1 ;  // You can use "gpio_pin_direction_intialize" instead of that
        TRISCbits.RC6 = 1 ;
        EUSART_Baud_Rate_Calculation(_eusart);
        if(EUSART_ASYNCHRONOUS_TX_ENABLE == _eusart->usart_tx_cfg.usart_tx_enable)EUSART_ASYNC_TX_Init(_eusart);
        if(EUSART_ASYNCHRONOUS_RX_ENABLE == _eusart->usart_rx_cfg.usart_rx_enable)EUSART_ASYNC_RX_Init(_eusart);
        RCSTAbits.SPEN = EUSART_MODULE_ENABLE;
    }
    return ret ;
}
Std_ReturnType EUSART_ASYNC_DeInit(const usart_t *_eusart){
    Std_ReturnType ret = E_OK ;
    if(NULL == _eusart){
        ret = E_NOT_OK;
    }else{
        RCSTAbits.SPEN = EUSART_MODULE_DISABLE ;
    }
    return ret ;
}
Std_ReturnType EUSART_ASYNC_ReadByteBlocking(uint8 *_data){
    Std_ReturnType ret = E_OK ;
    while(!PIR1bits.RCIF);
    *_data = RCREG;
    return ret ;
}
Std_ReturnType EUSART_ASYNC_ReadByteNonBlocking(uint8 *_data){
    Std_ReturnType ret = E_NOT_OK ;
    if(1 == PIR1bits.RCIF){
        *_data = RCREG ;
        ret = E_OK ;
    }else{
        ret = E_NOT_OK ;
    }
        return ret ;
}
Std_ReturnType EUSART_ASYNC_WriteByteBlocking(uint8 _data){
    Std_ReturnType ret = E_OK ;
    while(!TXSTAbits.TRMT);
    EUSART_TX_InterruptEnable();
    TXREG = _data ;
    return ret ;
}
Std_ReturnType EUSART_ASYNC_WriteStringBlocking(uint8 *_data ,uint16 str_length){
    Std_ReturnType ret = E_OK ;
    uint16 char_counter = ZERO_INIT ;
    for(char_counter=ZERO_INIT ; char_counter<str_length ; char_counter++){
        ret = EUSART_ASYNC_WriteByteBlocking(_data[char_counter]);
    }
    return ret;
}



static void EUSART_Baud_Rate_Calculation(const usart_t *_eusart){
    uint32 x =0;
    float Baud_Rate_Temp = 0;
    switch(_eusart->baudrate_gen_config){
        case BAUDRATE_ASYN_8BIT_LOW_SPEED : 
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_LOW_SPEED;
            BAUDCONbits.BRG16 = EUSART_08BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ / (float)_eusart->baudrate)/64)-1;
            break;
            case BAUDRATE_ASYN_8BIT_HIGH_SPEED : 
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_HIGH_SPEED;
            BAUDCONbits.BRG16 = EUSART_08BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ / (float)_eusart->baudrate)/16)-1;            
            break;
            case BAUDRATE_ASYN_16BIT_LOW_SPEED : 
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_LOW_SPEED;
            BAUDCONbits.BRG16 = EUSART_16BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ / (float)_eusart->baudrate)/16)-1; 
            break;
            case BAUDRATE_ASYN_16BIT_HIGH_SPEED : 
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_HIGH_SPEED;
            BAUDCONbits.BRG16 = EUSART_16BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ / (float)_eusart->baudrate)/4)-1; 
            break;
            case BAUDRATE_SYN_8BIT : 
            TXSTAbits.SYNC = EUSART_SYNCHRONOUS_MODE;
            BAUDCONbits.BRG16 = EUSART_08BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ / (float)_eusart->baudrate)/4)-1; 
            break;
            case BAUDRATE_SYN_16BIT : 
            TXSTAbits.SYNC = EUSART_SYNCHRONOUS_MODE;
            BAUDCONbits.BRG16 = EUSART_16BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ / (float)_eusart->baudrate)/4)-1; 
            break;   
        default : ;
    }
    SPBRG =(uint8)(Baud_Rate_Temp);//take the LSB 8bits of Baud_Rate_Temp
    SPBRGH =(uint8)(((uint16)Baud_Rate_Temp)>>8);//take the MSB 8bits of Baud_Rate_Temp
    
}
static void EUSART_ASYNC_TX_Init(const usart_t *_eusart){
    /* Transmission Enable */
    TXSTAbits.TXEN =EUSART_ASYNCHRONOUS_TX_ENABLE;
    /* EUSART TX Interrupt Configuration */
    if(EUSART_ASYNCHRONOUS_INTERRUPT_TX_ENABLE == _eusart->usart_tx_cfg.usart_tx_interrupt_enable){
        PIE1bits.TXIE = EUSART_ASYNCHRONOUS_INTERRUPT_TX_ENABLE;
#if EUSART_TX_INTERRUPT_FEATURE_ENABLE     ==     FEATURE_ENABLE
        EUSART_TX_InterruptEnable();  
        EUSART_TX_InterruptFlagClear();
        EUSART_TxInterruptHandler = _eusart->usart_tx_cfg.EUSART_TxDefaultInterruptHandler  ;
#if INTERRUPT_PRIORITY_LEVELS_ENABLE  ==   FEATURE_ENABLE
        INTERRUPT_PriorityLevelsEnable();
        if(INTERRUPT_HIGH_PRIORITY == _eusart ->usart_tx_cfg.TX_priority){
            EUSART_TX_HighPrioritySet();
            INTERRUPT_GlobalInturreptHighEnable();
        }
        else if(INTERRUPT_LOW_PRIORITY ==_eusart->usart_tx_cfg.TX_priority){
            EUSART_TX_LowPrioritySet();
            INTERRUPT_GlobalInturreptLowEnable();
        }
#else        
        INTERRUPT_GlobalInturreptEnable();
        INTERRUPT_PeripheralInterruptEnable();
#endif
#endif
    }
    else if(EUSART_ASYNCHRONOUS_INTERRUPT_TX_DISABLE == _eusart->usart_tx_cfg.usart_tx_interrupt_enable){
        PIE1bits.TXIE = EUSART_ASYNCHRONOUS_INTERRUPT_TX_DISABLE;
    }
    /* EUSART 9-Bit Transmit Enable */
    if(EUSART_ASYNCHRONOUS_9BIT_TX_ENABLE == _eusart->usart_tx_cfg.usart_tx_9bit_enable){
        TXSTAbits.TX9 = EUSART_ASYNCHRONOUS_9BIT_TX_ENABLE;
    }
    else if(EUSART_ASYNCHRONOUS_9BIT_TX_DISABLE == _eusart->usart_tx_cfg.usart_tx_9bit_enable){
        TXSTAbits.TX9 = EUSART_ASYNCHRONOUS_9BIT_TX_DISABLE;
    }
}
static void EUSART_ASYNC_RX_Init(const usart_t *_eusart){
    /* Receiver Enable */
    RCSTAbits.CREN = EUSART_ASYNCHRONOUS_RX_ENABLE;
    /* EUSART RX Interrupt Configuration */
    if(EUSART_ASYNCHRONOUS_INTERRUPT_RX_ENABLE == _eusart->usart_rx_cfg.usart_rx_interrupt_enable){
        PIE1bits.RCIE = EUSART_ASYNCHRONOUS_INTERRUPT_RX_ENABLE;
#if EUSART_RX_INTERRUPT_FEATURE_ENABLE     ==     FEATURE_ENABLE
        EUSART_RX_InterruptEnable();  
        EUSART_RX_InterruptFlagClear();
        EUSART_RxInterruptHandler = _eusart->usart_rx_cfg.EUSART_RxDefaultInterruptHandler ;
        EUSART_OverrunErrorHandler = _eusart->EUSART_OverrunErrorHandler ;
        EUSART_framingErrorHandler = _eusart->EUSART_framingErrorHandler ;
#if INTERRUPT_PRIORITY_LEVELS_ENABLE  ==   FEATURE_ENABLE
        INTERRUPT_PriorityLevelsEnable();
        if(INTERRUPT_HIGH_PRIORITY == _eusart ->usart_rx_cfg.RX_priority){
            EUSART_RX_HighPrioritySet();
            INTERRUPT_GlobalInturreptHighEnable();
        }
        else if(INTERRUPT_LOW_PRIORITY ==_eusart->usart_rx_cfg.RX_priority){
            EUSART_RX_LowPrioritySet();
            INTERRUPT_GlobalInturreptLowEnable();
        }
#else        
        INTERRUPT_GlobalInturreptEnable();
        INTERRUPT_PeripheralInterruptEnable();
#endif
#endif
    }
    else if(EUSART_ASYNCHRONOUS_INTERRUPT_RX_DISABLE == _eusart->usart_rx_cfg.usart_rx_interrupt_enable){
        PIE1bits.RCIE = EUSART_ASYNCHRONOUS_INTERRUPT_RX_DISABLE;
    }
    /* EUSART 9-Bit Receiver Enable */
    if(EUSART_ASYNCHRONOUS_9BIT_RX_ENABLE == _eusart->usart_rx_cfg.usart_rx_9bit_enable){
        RCSTAbits.RX9 = EUSART_ASYNCHRONOUS_9BIT_RX_ENABLE;
    }
    else if(EUSART_ASYNCHRONOUS_9BIT_RX_DISABLE == _eusart->usart_rx_cfg.usart_rx_9bit_enable){
        RCSTAbits.RX9 = EUSART_ASYNCHRONOUS_9BIT_RX_DISABLE;
    }
}



void EUSART_TX_ISR(void){
    EUSART_TX_InterruptFlagClear();
    EUSART_TX_InterruptDisable();
    if(EUSART_TxInterruptHandler){
        EUSART_TxInterruptHandler();
    }
}
void EUSART_RX_ISR(void){
    EUSART_RX_InterruptFlagClear();
    if(EUSART_RxInterruptHandler){
        EUSART_RxInterruptHandler();
    }else {/*Nothing*/}
    if(EUSART_framingErrorHandler){
        EUSART_framingErrorHandler();
    }else {/*Nothing*/}
    if(EUSART_OverrunErrorHandler){
        EUSART_OverrunErrorHandler();
    }else {/*Nothing*/} 
}

