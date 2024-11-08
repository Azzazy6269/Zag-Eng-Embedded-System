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

uint8 ones=0 , tens=0;
int main() {
    application_intialize();
    while(1){
        for(tens=0;tens<10;tens++){
            ret = gpio_port_write_logic(PORTD_INDEX,tens);
            for(ones=0;ones<10;ones++){
                ret = gpio_port_write_logic(PORTC_INDEX,ones);
                __delay_ms(250);
            }
        }
    }
    return (EXIT_SUCCESS);
}
void application_intialize(){
    ret = gpio_port_direction_intialize(PORTC_INDEX,0x80);
    ret = gpio_port_direction_intialize(PORTD_INDEX,0x80);
}

