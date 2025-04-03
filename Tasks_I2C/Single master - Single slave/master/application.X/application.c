/* 
 * File:   application.c
 * Author: moham
 *
 * Created on April 22, 2024, 5:52 AM
 */


#include "application.h"


mssp_i2c_t i2c_obj ;
uint8 Slave_ack;
uint8 trans;

#define SLAVE_1_Write 0x60  /* Address = 0x30(011 0000) + w Bit (0) => 0x60(0110 0000) */
#define SLAVE_2_Write 0x62  /* Address = 0x31(011 0001) + w Bit (0) => 0x62(0110 0010) */
#define SLAVE_1_Read  0x61  /* Address = 0x30(011 0000) + r Bit (1) => 0x60(0110 0001) */
#define SLAVE_2_Read  0x63  /* Address = 0x31(011 0001) + r Bit (1) => 0x62(0110 0011) */


void MSSP_I2C_Send_1_Byte(uint8 slave_add , uint8 _data){
    MSSP_I2C_Master_Send_Start(&i2c_obj);
    __delay_ms(10);
    MSSP_I2C_Master_Write_Blocking(&i2c_obj ,slave_add ,&Slave_ack);
    __delay_ms(10);
    MSSP_I2C_Master_Write_Blocking(&i2c_obj ,_data ,&Slave_ack);
    __delay_ms(10);
    MSSP_I2C_Master_Send_Stop(&i2c_obj);
    __delay_ms(10);
}
void I2C_DefaultInterruptHandler(void){
    trans++;
}


int main() {
    Std_ReturnType ret=E_NOT_OK;
    i2c_obj.i2c_clock = 100000 ;
    i2c_obj.i2c_cfg.i2c_mode = MSSP_I2C_MASTER_MODE ;
    i2c_obj.i2c_cfg.i2c_mode_cfg = I2C_MASTER_MODE_DEFINED_CLOCK ;
    i2c_obj.i2c_cfg.i2c_SMBus_control = i2c_SMBus_DISABLE ;
    i2c_obj.i2c_cfg.i2c_slew_rate = I2C_SLEW_RATE_DISABLE ;
    i2c_obj.I2C_DefaultInterruptHandler = I2C_DefaultInterruptHandler ;
    //i2c_obj.I2C_Report_Receive_OverFlow = NULL ;
    //i2c_obj.I2C_Report_Write_Collision = NULL ;
    application_intialize(); 
    MSSP_I2C_Init(&i2c_obj);
    while(1){
        MSSP_I2C_Send_1_Byte(SLAVE_1_Write,'f');
        __delay_ms(1000);
        MSSP_I2C_Send_1_Byte(SLAVE_1_Write,'g');
        __delay_ms(1000);
        MSSP_I2C_Send_1_Byte(SLAVE_1_Write,'h');
        __delay_ms(1000);
        MSSP_I2C_Send_1_Byte(SLAVE_1_Write,'o');
        __delay_ms(1000);
    }
    return (EXIT_SUCCESS);

}


void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK ;
    ret = led_intialize(&led1);
}



    