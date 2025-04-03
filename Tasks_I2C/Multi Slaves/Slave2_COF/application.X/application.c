/* 
 * File:   application.c
 * Author: moham
 *
 * Created on April 22, 2024, 5:52 AM
 */


#include "application.h"


mssp_i2c_t i2c_obj ;
volatile uint8 i2c_slave2_rec_counter ;



#define SLAVE_1_Write 0x60  /* Address = 0x30(011 0000) + w Bit (0) => 0x60(0110 0000) */
#define SLAVE_2_Write 0x62  /* Address = 0x31(011 0001) + w Bit (0) => 0x62(0110 0010) */
#define SLAVE_1_Read  0x61  /* Address = 0x30(011 0000) + w Bit (0) => 0x60(0110 0001) */
#define SLAVE_2_Read  0x63  /* Address = 0x31(011 0001) + w Bit (0) => 0x62(0110 0011) */


void I2C_DefaultInterruptHandler(void){
    i2c_slave2_rec_counter++;
}


int main() {
    Std_ReturnType ret = E_NOT_OK ;
    i2c_obj.i2c_cfg.i2c_mode = MSSP_I2C_SLAVE_MODE ;
    i2c_obj.i2c_cfg.i2c_mode_cfg = I2C_SLAVE_MODE_7BIT_ADDRESS ;
    i2c_obj.i2c_cfg.i2c_slave_address = 0x60 ;
    i2c_obj.i2c_cfg.i2c_general_call = I2C_GENERAL_CALL_DISABLE ;       
    i2c_obj.i2c_cfg.i2c_SMBus_control = i2c_SMBus_DISABLE ;
    i2c_obj.i2c_cfg.i2c_slew_rate = I2C_SLEW_RATE_DISABLE ;
    i2c_obj.I2C_DefaultInterruptHandler = I2C_DefaultInterruptHandler ;
    //i2c_obj.I2C_Report_Receive_OverFlow = NULL ;
    //i2c_obj.I2C_Report_Write_Collision = NULL ;
    application_intialize(); 
    MSSP_I2C_Init(&i2c_obj);
    while(1){
        
    }
    return (EXIT_SUCCESS);

}


void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK ;
    ret = led_intialize(&led1);
}



    