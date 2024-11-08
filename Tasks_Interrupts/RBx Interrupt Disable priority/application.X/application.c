/* 
 * File:   application.c
 * Author: moham
 *
 * Created on April 22, 2024, 5:52 AM
 */


#include "application.h"

interrupt_RBx_t RB4_obj = {
    .EXT_InterruptHandlerHigh = RB4_APP_ISR_High,
    .EXT_InterruptHandlerLow  = RB4_APP_ISR_Low,
    .priority = INTERRUPT_HIGH_PRIORITY,
    .mcu_pin.port = PORTB_INDEX,
    .mcu_pin.pin = GPIO_PIN4,
    .mcu_pin.direction = GPIO_DIRECTION_INPUT
};
interrupt_RBx_t RB5_obj = {
    .EXT_InterruptHandlerHigh = RB5_APP_ISR_High,
    .EXT_InterruptHandlerLow  = RB5_APP_ISR_Low,
    .priority = INTERRUPT_HIGH_PRIORITY,
    .mcu_pin.port = PORTB_INDEX,
    .mcu_pin.pin = GPIO_PIN5,
    .mcu_pin.direction = GPIO_DIRECTION_INPUT
};
interrupt_RBx_t RB6_obj = {
    .EXT_InterruptHandlerHigh = RB6_APP_ISR_High,
    .EXT_InterruptHandlerLow  = RB6_APP_ISR_Low,
    .priority = INTERRUPT_HIGH_PRIORITY,
    .mcu_pin.port = PORTB_INDEX,
    .mcu_pin.pin = GPIO_PIN6,
    .mcu_pin.direction = GPIO_DIRECTION_INPUT
};
interrupt_RBx_t RB7_obj = {
    .EXT_InterruptHandlerHigh = RB7_APP_ISR_High,
    .EXT_InterruptHandlerLow  = RB7_APP_ISR_Low,
    .priority = INTERRUPT_HIGH_PRIORITY,
    .mcu_pin.port = PORTB_INDEX,
    .mcu_pin.pin = GPIO_PIN7,
    .mcu_pin.direction = GPIO_DIRECTION_INPUT
};

int main() {
    Std_ReturnType ret=E_NOT_OK;
    application_intialize();
    while(1){
     
    }
    return (EXIT_SUCCESS);
}

void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK ;
    ret = led_intialize(&led0);
    ret = led_intialize(&led1);
    ret = led_intialize(&led2);
    ret = led_intialize(&led3);
    ret = Interrupt_RBx_Init(&RB4_obj);
    ret = Interrupt_RBx_Init(&RB5_obj);
    ret = Interrupt_RBx_Init(&RB6_obj);
    ret = Interrupt_RBx_Init(&RB7_obj);
    

}

void RB4_APP_ISR_High(void){
    led_turn_toggle(&led0);
    }   
void RB4_APP_ISR_Low(void){
    led_turn_toggle(&led0);
    }
void RB5_APP_ISR_High(void){
    led_turn_toggle(&led1);
    }   
void RB5_APP_ISR_Low(void){
    led_turn_toggle(&led1);
    }
void RB6_APP_ISR_High(void){
    led_turn_toggle(&led2);
    }   
void RB6_APP_ISR_Low(void){
    led_turn_toggle(&led2);
    }
void RB7_APP_ISR_High(void){
    led_turn_toggle(&led3);
    }   
void RB7_APP_ISR_Low(void){
    led_turn_toggle(&led3);
    }

    