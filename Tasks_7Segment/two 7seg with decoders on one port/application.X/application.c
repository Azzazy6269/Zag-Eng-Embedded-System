/* 
 * File:   application.c
 * Author: moham
 *
 * Created on April 22, 2024, 5:52 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "application.h"
#include "ECU_Layer/relay/relay.h"
#include "ECU_Layer/DC_motor/DC_motor.h"
 
Std_ReturnType ret=E_NOT_OK;
static uint8 number = 0, number_bcd =0;
uint8 ones=0 , tens=0;
int main() {
    application_intialize();
    while(1){
        number_bcd = (((uint8 )number%10)|(((uint8)number/10)<<4));
        ret = gpio_port_write_logic(PORTC_INDEX,number_bcd);
        number++;
        __delay_ms(100);
        if(number>99){
            number =0;
        }
    }
    return (EXIT_SUCCESS);
}
void application_intialize(){
    ret = gpio_port_direction_intialize(PORTC_INDEX,0x00);
}

