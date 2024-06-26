/* 
 * File:   application.c
 * Author: moham
 *
 * Created on April 22, 2024, 5:52 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "application.h"


pin_config_t led_1 ={
    .port = PORTC_INDEX,
    .pin = GPIO_PIN0,
    .direction = GPIO_DIRECTION_OUTPUT,
    .logic = GPIO_LOW
};

pin_config_t led_2 ={
    .port = PORTC_INDEX,
    .pin = GPIO_PIN1,
    .direction = GPIO_DIRECTION_OUTPUT,
    .logic = GPIO_LOW
};

pin_config_t led_3 ={
    .port = PORTC_INDEX,
    .pin = GPIO_PIN2,
    .direction = GPIO_DIRECTION_OUTPUT,
    .logic = GPIO_LOW
};

pin_config_t btn_1 ={
    .port = PORTD_INDEX,
    .pin = GPIO_PIN0,
    .direction = GPIO_DIRECTION_INPUT,
    .logic = GPIO_LOW
};

Std_ReturnType ret = E_NOT_OK ;
direction_t led_1_st ;
//logic_t btn1_status;
//uint8 portc_direction_status , portc_logic_status ;
int main() {
    
    application_intialize();

    while(1){
    ret = gpio_pin_write_logic(&led_3,GPIO_LOW);
    ret = gpio_pin_write_logic(&led_1,GPIO_HIGH);
    __delay_ms(60000);
    ret = gpio_pin_write_logic(&led_1,GPIO_LOW);
    ret = gpio_pin_write_logic(&led_2,GPIO_HIGH);
    __delay_ms(10000);
    ret = gpio_pin_write_logic(&led_2,GPIO_LOW);
    ret = gpio_pin_write_logic(&led_3,GPIO_HIGH);
    __delay_ms(60000);     
    }
    
    return (EXIT_SUCCESS);
}
void application_intialize(){
    ret = gpio_pin_intialize(&led_1);    
    ret = gpio_pin_intialize(&led_2);    
    ret = gpio_pin_intialize(&led_3);
   /* ret = gpio_port_direction_intialize(PORTC_INDEX,0x00);
    ret = gpio_port_get_direction_status(PORTC_INDEX,&portc_direction_status);
    ret = gpio_port_write_logic(PORTC_INDEX,0x55);
    ret = gpio_port_read_logic(PORTC_INDEX,&portc_logic_status);*/
}
