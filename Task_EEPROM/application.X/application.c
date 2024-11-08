/* 
 * File:   application.c
 * Author: moham
 *
 * Created on April 22, 2024, 5:52 AM
 */


#include "application.h"

uint8 eeprom_val = 0 ,eeprom_val_read=0;

int main() {
    Std_ReturnType ret=E_NOT_OK;
    application_intialize();
    while(1){
        Data_EEPROM_WriteByte(0x03FF , eeprom_val++);
        ret = Data_EEPROM_ReadByte(0x03ff,&eeprom_val_read);
        if((eeprom_val_read % 5)==0){
            led_turn_toggle(&led0);
        }
        __delay_ms(1000);
        
    }
    return (EXIT_SUCCESS);
}

void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK ;
    ret =led_intialize(&led0);
    
}



    