/* 
 * File:   application.c
 * Author: moham
 *
 * Created on April 22, 2024, 5:52 AM
 */


#include "application.h"
interrupt_INTx_t int0_obj = {
    .EXT_InterruptHandler = Int0_APP_ISR,
    .edge = INTERRUPT_RISING_EDGE,
    .priority = INTERRUPT_HIGH_PRIORITY,
    .source = INTERRUPT_EXTERNAL_INT0,
    .mcu_pin.port = PORTB_INDEX,
    .mcu_pin.pin = GPIO_PIN0,
    .mcu_pin.direction = GPIO_DIRECTION_INPUT
};
interrupt_INTx_t int1_obj = {
    .EXT_InterruptHandler = Int1_APP_ISR,
    .edge = INTERRUPT_RISING_EDGE,
    .priority = INTERRUPT_LOW_PRIORITY,
    .source = INTERRUPT_EXTERNAL_INT1,
    .mcu_pin.port = PORTB_INDEX,
    .mcu_pin.pin = GPIO_PIN1,
    .mcu_pin.direction = GPIO_DIRECTION_INPUT
};
interrupt_INTx_t int2_obj = {
    .EXT_InterruptHandler = Int2_APP_ISR,
    .edge = INTERRUPT_RISING_EDGE,
    .priority = INTERRUPT_HIGH_PRIORITY,
    .source = INTERRUPT_EXTERNAL_INT2,
    .mcu_pin.port = PORTB_INDEX,
    .mcu_pin.pin = GPIO_PIN2,
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
    ret = Interrupt_INTx_Init(&int0_obj);
    ret = Interrupt_INTx_Init(&int1_obj);
    ret = Interrupt_INTx_Init(&int2_obj);

}

void Int0_APP_ISR(void){
    for(uint8 i=0;i<100;i++){
    led_turn_toggle(&led0);
    __delay_ms(100);
    }   
}
void Int1_APP_ISR(void){
    for(uint8 i=0;i<100;i++){
    led_turn_toggle(&led1);
    __delay_ms(100);
    }     
}
void Int2_APP_ISR(void){
    for(uint8 i=0;i<100;i++){
    led_turn_toggle(&led2);
    __delay_ms(100);
    }     
}