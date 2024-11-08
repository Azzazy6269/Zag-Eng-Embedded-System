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

 

relay_t relay_1 ={
  .relay_port = PORTC_INDEX,
  .relay_pin  = GPIO_PIN0,
  .relay_status = RELAY_OFF_STATUS
};

Std_ReturnType ret=E_NOT_OK;

int main() {
    application_intialize();
    while(1){
      ret = relay_turn_on(&relay_1);
      __delay_ms(5000);
      ret = relay_turn_off(&relay_1);
      __delay_ms(5000);
    }
    return (EXIT_SUCCESS);
    }

void application_intialize(){
    ret =relay_intialize(&relay_1);
}

