/* 
 * File:   I2C.h
 * Author: smart
 *
 * Created on 12 Oct, 2024, 01:40 
 */

#include "I2C.h"
#if MSSP_I2C_INTERRUPT_FEATURE_ENABLE   ==  FEATURE_ENABLE
static  void (* I2C_InterruptHandler)(void)=NULL;
static  void (* BUS_COLLISION_InterruptHandler)(void)=NULL;
static  void (* Receive_OverFlow_InterruptHandler)(void)=NULL;
#endif
static inline void MSSP_I2C_Mode_GPIO_CFG(void);
static inline void I2C_Master_Mode_Clock_Configuratins(const mssp_i2c_t * i2c_obj);
static inline void I2C_Slave_Mode_Configurations(const mssp_i2c_t *i2c_obj);
static inline void MSSP_I2C_Interrupt_Configurations(const mssp_i2c_t * i2c_obj);





Std_ReturnType MSSP_I2C_Init(const mssp_i2c_t * i2c_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == i2c_obj){
       ret = E_NOT_OK; 
    }
    else{
        /* Disable MSSP I2C Module */
        MSSP_MODULE_DISABLE();
        /* I2C GPIO Configurations */
        MSSP_I2C_Mode_GPIO_CFG();
        /* MSSP I2C mode Select */
        if(i2c_obj->i2c_cfg.i2c_mode == MSSP_I2C_MASTER_MODE){
            I2C_Master_Mode_Clock_Configuratins(i2c_obj);
        }else if (i2c_obj->i2c_cfg.i2c_mode == MSSP_I2C_SLAVE_MODE){
            if(I2C_GENERAL_CALL_ENABLE == i2c_obj->i2c_cfg.i2c_general_call){I2C_GENERAL_CALL_ENABLE_CFG();}
            else if(I2C_GENERAL_CALL_DISABLE == i2c_obj->i2c_cfg.i2c_general_call){I2C_GENERAL_CALL_DISABLE_CFG();}
            /* Clear the write collision detection */
            SSPCON1bits.WCOL = 0; /* No Collision */
            /* Clear the Receive Overflow Indicator */
            SSPCON1bits.SSPOV = 0;
            /* Release the clock */
            SSPCON1bits.CKP = 1; /* if 0 it will hold the clock so the master can not send more data ,, 
                                  * we write 0 if the transmission rate is so high or the slave wants some time to do process before receiving more data  
            /* Assign the I2C slave Address */
            SSPADD = i2c_obj->i2c_cfg.i2c_slave_address ;
            /*  Slave mode configuration*/
            I2C_Slave_Mode_Configurations(i2c_obj);
        }    
        /* MSSP I2C Slew Rate Control */
        if(I2C_SLEW_RATE_DISABLE == i2c_obj->i2c_cfg.i2c_slew_rate){I2C_SLEW_RATE_DISABLE_CFG();}
        else if(I2C_SLEW_RATE_ENABLE == i2c_obj->i2c_cfg.i2c_slew_rate){I2C_SLEW_RATE_ENABLE_CFG();}
        /* MSSP I2C SMBus Control */
        if(i2c_SMBus_DISABLE == i2c_obj->i2c_cfg.i2c_SMBus_control){I2C_SLEW_RATE_DISABLE_CFG();}
        else if(i2c_SMBus_ENABLE == i2c_obj->i2c_cfg.i2c_SMBus_control){I2C_SLEW_RATE_ENABLE_CFG();}
        /* Interrupt Configuration */
        MSSP_I2C_Interrupt_Configurations(&i2c_obj);
        /* Enable MSSP I2C Module */
        MSSP_MODULE_ENABLE();
    }
    return ret;
}
Std_ReturnType MSSP_I2C_DeInit(const mssp_i2c_t * i2c_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == i2c_obj){
       ret = E_NOT_OK; 
    }
    else{
        /* Disable MSSP I2C Module */
        MSSP_MODULE_DISABLE();
        /* Interrupt Disable */
#if MSSP_I2C_INTERRUPT_FEATURE_ENABLE   ==  FEATURE_ENABLE
            I2C_InterruptDisable();
            MSSP_I2C_BOS_COL_InterruptDisable();
#endif            
    }
    return ret ;
}
Std_ReturnType MSSP_I2C_Master_Send_Start(const mssp_i2c_t * i2c_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == i2c_obj){
       ret = E_NOT_OK; 
    }
    else{
        /* Initiates Start condition on SDA and SCL pins */
        SSPCON2bits.SEN = 1;    /*Automatically Cleared by Hardware*/
        /* Wait for the completion of the start condition */
        while(SSPCON2bits.SEN);
        /* Clear MSSP Interrupt flag bit */
        PIR1bits.SSPIF =0 ;
        /* Report The Start Condition Detection */
        if(START_BIT_NOT_DETECTED == SSPSTATbits.S){
            ret = E_NOT_OK ;
        }
    }
    return ret;
}
Std_ReturnType MSSP_I2C_Master_Send_Repeated_Start(const mssp_i2c_t * i2c_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == i2c_obj){
       ret = E_NOT_OK; 
    }
    else{
        /* Intiates Repeated Start condition on SDA and SCL pins */
        SSPCON2bits.RSEN = 1 ;   /* Automatically cleared by hardware */
        /* Wait for the completion of the Repeated Start condition */
        while(SSPCON2bits.RSEN);
        /* Clear The MSSP Interrupt Flag bit */
        PIR1bits.SSPIF =0 ;
    }
    return ret ;
}
Std_ReturnType MSSP_I2C_Master_Send_Stop(const mssp_i2c_t * i2c_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == i2c_obj){
       ret = E_NOT_OK; 
    }
    else{
        /* Intiates Stop condition on SDA and SCL pins */
        SSPCON2bits.PEN = 1 ;    /* Automatically cleared by hardware */
        /* Wait for the competition of the stop condition */
        while(SSPCON2bits.PEN);
        /* Clear MSSP Interrupt Flag */
        PIR1bits.SSPIF =0 ;
        /* Report The Stop Condition Detection */
        if(STOP_BIT_NOT_DETECTED == SSPSTATbits.P){
            ret = E_NOT_OK ;
        }
    }
}
Std_ReturnType MSSP_I2C_Master_Write_Blocking(const mssp_i2c_t * i2c_obj,uint8 i2c_data, uint8 *_ack){
    Std_ReturnType ret = E_OK;
    if(NULL == i2c_obj){
       ret = E_NOT_OK; 
    }
    else{
        /* Write data to the data register */
        SSPBUF = i2c_data ;
        /* Wait the transmission to be completed */
        while(!PIR1bits.SSPIF);
        /* Clear MSSP Interrupt flag */
        PIR1bits.SSPIF = 0;
        /* Report the acknowledge received */
        if(I2C_ACK_RECEIVED_FROM_SLAVE == SSPCON2bits.ACKSTAT){*_ack =I2C_ACK_RECEIVED_FROM_SLAVE;}
        else {*_ack =I2C_ACK_RECEIVED_FROM_SLAVE ;}
    }
    return ret ;
}
Std_ReturnType MSSP_I2C_Master_Read_Blocking(const mssp_i2c_t * i2c_obj,uint8 ack,uint8 *i2c_data){
    Std_ReturnType ret = E_OK;
    if((NULL == i2c_obj)||(NULL == i2c_data)){
       ret = E_NOT_OK; 
    }
    else{
        /* Master Mode Receive Enable */
        I2C_MASTER_RECEIVE_ENABLE_CFG();
        /* Wait for buffer full flag : A complete byte received */
        while(!SSPSTATbits.BF);
        /* Copy The data registers to buffer variable */
        *i2c_data = SSPBUF;
        /* Send ACK or NACK after read */
        if(I2C_MASTER_SEND_ACK ==ack){
            SSPCON2bits.ACKDT = 0; /* Acknowledge */
            SSPCON2bits.ACKEN = 1; /* Intiates Acknowledge sequence on SDA and SCL pins and transmit ACKDT data bit */
        }
        else if(I2C_MASTER_SEND_NACK ==ack){
            SSPCON2bits.ACKDT = 1;/* Not Acknowledge */
            SSPCON2bits.ACKEN = 1;/* Intiates Acknowledge sequence on SDA and SCL pins and transmit ACKDT data bit */
        }
    }
    return ret ;
}
void MSSP_I2C_ISR(void){
#if MSSP_I2C_INTERRUPT_FEATURE_ENABLE   ==  FEATURE_ENABLE
    I2C_InterruptFlagClear();
    if(I2C_InterruptHandler){
        I2C_InterruptHandler();
    }
#endif
}
void MSSP_I2C_Bus_Collision_ISR(void){
#if MSSP_I2C_INTERRUPT_FEATURE_ENABLE   ==  FEATURE_ENABLE    
    I2C_BUS_COL_InterruptFlagClear();
    if(BUS_COLLISION_InterruptHandler){
        BUS_COLLISION_InterruptHandler();
    }
#endif
}

static inline void MSSP_I2C_Mode_GPIO_CFG(void){
    TRISCbits.TRISC3 = 1 ; /* Serial clock (SCL) is Input */
    TRISCbits.TRISC4 = 1 ; /* Serial data (SDA) is Input */
}

static inline void I2C_Master_Mode_Clock_Configuratins(const mssp_i2c_t * i2c_obj){
    SSPCON1bits.SSPM = i2c_obj->i2c_cfg.i2c_mode_cfg ;
    SSPADD = (uint8)(((_XTAL_FREQ/4.0)/i2c_obj->i2c_clock)-1);
}

static inline void I2C_Slave_Mode_Configurations(const mssp_i2c_t *i2c_obj){
    SSPCON1bits.SSPM = i2c_obj->i2c_cfg.i2c_mode_cfg ;
}

static inline void MSSP_I2C_Interrupt_Configurations(const mssp_i2c_t * i2c_obj){
    #if MSSP_I2C_INTERRUPT_FEATURE_ENABLE      ==     FEATURE_ENABLE
        I2C_InterruptEnable();
        I2C_InterruptFlagClear();
        MSSP_I2C_BUS_COL_InterruptEnable();
        I2C_BUS_COL_InterruptFlagClear();
        I2C_InterruptHandler =i2c_obj ->I2C_DefaultInterruptHandler ;
        BUS_COLLISION_InterruptHandler =i2c_obj ->I2C_Report_Write_Collision ;
        Receive_OverFlow_InterruptHandler =i2c_obj ->I2C_Report_Receive_OverFlow ;
#if INTERRUPT_PRIORITY_LEVELS_ENABLE  ==   FEATURE_ENABLE
        INTERRUPT_PriorityLevelsEnable();
        if(INTERRUPT_HIGH_PRIORITY == i2c_obj ->i2c_cfg.i2c_priority){
            I2C_HighPrioritySet();
            INTERRUPT_GlobalInturreptHighEnable();
        }
        else if(INTERRUPT_LOW_PRIORITY ==i2c_obj->i2c_cfg.i2c_priority){
            I2C_LowPrioritySet();
            INTERRUPT_GlobalInturreptLowEnable();
        }
        if(INTERRUPT_HIGH_PRIORITY == i2c_obj ->i2c_cfg.bus_collision_priority){
            I2C_BUS_COL_HighPrioritySet();
            INTERRUPT_GlobalInturreptHighEnable();
        }
        else if(INTERRUPT_LOW_PRIORITY ==i2c_obj->i2c_cfg.bus_collision_priority){
            I2C_BUS_COL_LowPrioritySet();
            INTERRUPT_GlobalInturreptLowEnable();
        }
#else        
        INTERRUPT_GlobalInturreptEnable();
        INTERRUPT_PeripheralInterruptEnable();
#endif
#endif
}