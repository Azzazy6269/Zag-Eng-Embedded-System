/* 
 * File:   I2C.h
 * Author: smart
 *
 * Created on 12 Oct, 2024, 01:40 ?
 */

#ifndef I2C_H
#define	I2C_H

/* ---------------Section : Includes----------------- */
#include "../mcal_std_types.h"
#include "C:\Program Files\Microchip\MPLABX\v6.20\packs\Microchip\PIC18Fxxxx_DFP\1.6.159\xc8\pic\include\proc\pic18f4620.h"
#include "../GPIO/hal_gpio.h"
#include "../Interrupt/Internal_interrupt.h"

/* ----------------Section : MACRO Declerations---------------- */
/* i2c_mode_cfg */
#define I2C_SLAVE_MODE_7BIT_ADDRESS                                   0x06U
#define I2C_SLAVE_MODE_10BIT_ADDRESS                                  0x07U
#define I2C_SLAVE_MODE_7BIT_ADDRESS_SS_INTERRUPT_ENABLE               0x0EU
#define I2C_SLAVE_MODE_10BIT_ADDRESS_SS_INTERRUPT_ENABLE              0x0FU
#define I2C_MASTER_MODE_DEFINED_CLOCK                                 0x08U
#define I2C_MASTER_MODE_FRIMWARE_CONTROLLED                           0x0BU
/* i2c_mode */
#define MSSP_I2C_MASTER_MODE 1
#define MSSP_I2C_SLAVE_MODE 0
/*i2c_slew_rate*/
#define I2C_SLEW_RATE_DISABLE 1
#define I2C_SLEW_RATE_ENABLE  0
/*i2c_SMBus_control*/
#define i2c_SMBus_DISABLE 1
#define i2c_SMBus_ENABLE  0
/* i2c_general_call */
#define I2C_GENERAL_CALL_ENABLE 1
#define I2C_GENERAL_CALL_DISABLE 0
/* i2c_master_rec_mode */
#define I2C_MASTER_RECEIVE_ENABLE 1
#define I2C_MASTER_RECEIVE_DISABLE 0
/* Slave Node Data/Address Indication */
#define I2C_LAST_BYTE_DATA 1
#define I2C_LAST_BYTE_ADDRESS 0
/* Stop Condition Indication */
#define STOP_BIT_DETECTED 1
#define STOP_BIT_NOT_DETECTED 0
/* Start Condition Indication */
#define START_BIT_DETECTED 1
#define START_BIT_NOT_DETECTED 0
/* Acknowledge Status bit (Master Transmit mode only) */
#define I2C_ACK_RECEIVED_FROM_SLAVE      0
#define I2C_ACK_NOT_RECEIVED_FROM_SLAVE  1
/* Acknowledge Data bit (Master Receive mode only) */
#define I2C_MASTER_SEND_ACK  (uint8)0
#define I2C_MASTER_SEND_NACK (uint8)1 


/* ----------------Section : MACRO Functions Declerations------------------ */
/* Slew Rate Enable/Disable */
#define I2C_SLEW_RATE_DISABLE_CFG()             (SSPSTATbits.SMP = 1)
#define I2C_SLEW_RATE_ENABLE_CFG()              (SSPSTATbits.SMP = 0)
/* SMBus Enable/Disable */
#define I2C_SMBus_DISABLE_CFG()                 (SSPSTATbits.CKE = 0)
#define I2C_SMBus_ENABLE_CFG()                  (SSPSTATbits.CKE = 1)
/* General Call Enable */
#define I2C_GENERAL_CALL_DISABLE_CFG()          (SSPCON2bits.GCEN = 0)
#define I2C_GENERAL_CALL_ENABLE_CFG()           (SSPCON2bits.GCEN = 1)
/* Master Mode Receive Enable */
#define I2C_MASTER_RECEIVE_DISABLE_CFG()        (SSPCON2bits.RCEN = 0)
#define I2C_MASTER_RECEIVE_ENABLE_CFG()         (SSPCON2bits.RCEN = 1)
/* MSSP MODULE ENABLE AND DISABLE */
#define MSSP_MODULE_ENABLE()                    (SSPCON1bits.SSPEN = 1)
#define MSSP_MODULE_DISABLE()                   (SSPCON1bits.SSPEN = 0)
/* Clock Stretch */
#define I2C_CLOCK_STRETCH_ENABLE()              (SSPCON1bits.CKP = 0)
#define I2C_CLOCK_STRETCH_DISABLE()             (SSPCON1bits.CKP = 1)
/* ----------------Section : Data Types Declerations-------------- */
typedef struct{
    uint8 i2c_mode_cfg;              /* Master Synchronous Serial Port Mode Select */
    uint8 i2c_mode : 1 ;             /* I2C : Master or Slave Mode */ 
    uint8 i2c_slave_address ;        /* Only used in slave mode */
    uint8 i2c_slew_rate : 1 ;        /* Slew rate Enable/Disable */
    uint8 i2c_SMBus_control : 1 ;    /* SMBus Enable/Disable */
    uint8 i2c_general_call : 1 ;     /* General Call Enable/Disable */
    uint8 i2c_master_rec_mode : 1 ;  /* Master Receive Mode Enable/Disable */
    uint8 i2c_reversed : 3 ;
#if MSSP_I2C_INTERRUPT_FEATURE_ENABLE      ==     FEATURE_ENABLE
    interrupt_priority_cfg i2c_priority;
    interrupt_priority_cfg bus_collision_priority;
    interrupt_priority_cfg receive_collision_priority;
#endif
}i2c_configure_t;

typedef struct{
    uint32 i2c_clock ; /* Master Clock Frequency */ /* used only in master mode */
#if MSSP_I2C_INTERRUPT_FEATURE_ENABLE      ==     FEATURE_ENABLE
    void (*I2C_Report_Write_Collision)(void);    /* Write Collision Indicator */
    void (*I2C_Report_Receive_OverFlow)(void);   /* Write OverFlow Indicator */
    void (*I2C_DefaultInterruptHandler)(void);   /* Default Interrupt Handler */ 
#endif
    i2c_configure_t i2c_cfg ; /* I2C Configurations */
}mssp_i2c_t;

/* ------------------Section : Function Declerations---------------- */
Std_ReturnType MSSP_I2C_Init(const mssp_i2c_t * i2c_obj);
Std_ReturnType MSSP_I2C_DeInit(const mssp_i2c_t * i2c_obj);
Std_ReturnType MSSP_I2C_Master_Send_Start(const mssp_i2c_t * i2c_obj);
Std_ReturnType MSSP_I2C_Master_Send_Repeated_Start(const mssp_i2c_t * i2c_obj);
Std_ReturnType MSSP_I2C_Master_Send_Stop(const mssp_i2c_t * i2c_obj);
Std_ReturnType MSSP_I2C_Master_Write_Blocking(const mssp_i2c_t * i2c_obj,uint8 i2c_data, uint8 *_ack);
Std_ReturnType MSSP_I2C_Master_Read_Blocking(const mssp_i2c_t * i2c_obj,uint8 ack,uint8 *i2c_data);



#endif	/* I2C_H */

