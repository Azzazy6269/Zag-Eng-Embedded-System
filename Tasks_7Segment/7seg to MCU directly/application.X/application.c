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

int main() {
    application_intialize();
    while(1){
        
    }
    return (EXIT_SUCCESS);
}
void application_intialize(){
    ret = gpio_port_direction_intialize(PORTC_INDEX,0x80);
    ret = gpio_port_direction_intialize(PORTD_INDEX,0x80);

}

