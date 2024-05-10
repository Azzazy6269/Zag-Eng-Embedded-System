/* 
 * File:   application.c
 * Author: moham
 *
 * Created on April 22, 2024, 5:52 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "application.h"

led_t led1 ={.port_name =PORTC_INDEX,.pin=  GPIO_PIN0,.led_status = GPIO_LOW};
led_t led2 ={.port_name =PORTC_INDEX,.pin=  GPIO_PIN1,.led_status = GPIO_LOW};
led_t led3 ={.port_name =PORTC_INDEX,.pin=  GPIO_PIN2, .led_status = GPIO_LOW};
led_t led4 ={.port_name =PORTC_INDEX,.pin=  GPIO_PIN3, .led_status = GPIO_LOW};
led_t led5 ={.port_name =PORTC_INDEX,.pin=  GPIO_PIN4,.led_status = GPIO_LOW};
led_t led6 ={.port_name =PORTC_INDEX,.pin=  GPIO_PIN5,.led_status = GPIO_LOW};
led_t led7 ={.port_name =PORTC_INDEX,.pin=  GPIO_PIN6, .led_status = GPIO_LOW};
led_t led8 ={.port_name =PORTC_INDEX,.pin=  GPIO_PIN7, .led_status = GPIO_LOW};
Std_ReturnType ret = E_NOT_OK ;
button_t btn_high = {
    .button_pin.port =PORTD_INDEX,
    .button_pin.pin =GPIO_PIN0,
    .button_pin.direction =GPIO_DIRECTION_INPUT,
    .button_pin.logic =GPIO_LOW,
    .button_connection =BUTTON_ACTIVE_HIGH,
    .button_state =BUTTON_RELEASED
};
button_t btn_low = {
    .button_pin.port =PORTD_INDEX,
    .button_pin.pin =GPIO_PIN1,
    .button_pin.direction =GPIO_DIRECTION_INPUT,
    .button_pin.logic =GPIO_LOW,
    .button_connection =BUTTON_ACTIVE_LOW,
    .button_state =BUTTON_RELEASED
};           
  button_state_t btn_high_status = BUTTON_RELEASED;    
  button_state_t btn_low_status = BUTTON_RELEASED;      
  
  button_state_t btn_high_valid_status = BUTTON_RELEASED;
  button_state_t btn_high_last_valid_status = BUTTON_RELEASED;
 uint32 btn_high_valid =BUTTON_RELEASED;
  button_state_t btn_low_valid_status = BUTTON_RELEASED;
  button_state_t btn_low_last_valid_status = BUTTON_RELEASED;
 uint32 btn_low_valid =BUTTON_RELEASED; 
 
 uint8 program_selected =0;
  
 
 // program selected tasks
 void program_1(void){
    led_turn_off(&led8);
    led_turn_off(&led7);
    led_turn_off(&led6);
    led_turn_off(&led5);
    led_turn_off(&led4);
    led_turn_off(&led3);
    led_turn_off(&led2);
    led_turn_off(&led1);
    __delay_ms(200);
     for(uint8 i=0;i<10;i++){
    led_turn_toggle(&led1);
    led_turn_toggle(&led2);
    led_turn_toggle(&led3);
    led_turn_toggle(&led4);
    led_turn_toggle(&led5);
    led_turn_toggle(&led6);
    led_turn_toggle(&led7);
    led_turn_toggle(&led8);
   __delay_ms(500);
 }
}

void program_2(void){
    led_turn_on(&led1);
    led_turn_off(&led2);
    led_turn_off(&led3);
    led_turn_off(&led4);
    led_turn_off(&led5);
    led_turn_off(&led6);
    led_turn_off(&led7);
    led_turn_off(&led8);
    __delay_ms(250);
    led_turn_toggle(&led1);
    led_turn_toggle(&led2);
    __delay_ms(250);
    led_turn_toggle(&led2);
    led_turn_toggle(&led3);   
    __delay_ms(250);
    led_turn_toggle(&led3);
    led_turn_toggle(&led4);   
    __delay_ms(250);
    led_turn_toggle(&led4);
    led_turn_toggle(&led5);   
    __delay_ms(250);
    led_turn_toggle(&led5);
    led_turn_toggle(&led6);   
    __delay_ms(250);
    led_turn_toggle(&led6);
    led_turn_toggle(&led7);  
    __delay_ms(250);
    led_turn_toggle(&led7);
    led_turn_toggle(&led8);
    __delay_ms(250);
}

void program_3(void){
    led_turn_on(&led8);
    led_turn_off(&led7);
    led_turn_off(&led6);
    led_turn_off(&led5);
    led_turn_off(&led4);
    led_turn_off(&led3);
    led_turn_off(&led2);
    led_turn_off(&led1);
    __delay_ms(250);
    led_turn_toggle(&led8);
    led_turn_toggle(&led7);
    __delay_ms(250);
    led_turn_toggle(&led7);
    led_turn_toggle(&led6);   
    __delay_ms(250);
    led_turn_toggle(&led6);
    led_turn_toggle(&led5);   
    __delay_ms(250);
    led_turn_toggle(&led5);
    led_turn_toggle(&led4);   
    __delay_ms(250);
    led_turn_toggle(&led4);
    led_turn_toggle(&led3);   
    __delay_ms(250);
    led_turn_toggle(&led3);
    led_turn_toggle(&led2);  
    __delay_ms(250);
    led_turn_toggle(&led2);
    led_turn_toggle(&led1);
    __delay_ms(250);
}

void program_4(void){
   for(uint8 i=0;i<10;i++){
     led_turn_on(&led1);
    led_turn_off(&led2);
    led_turn_on(&led3);
    led_turn_off(&led4);
    led_turn_on(&led5);
    led_turn_off(&led6);
    led_turn_on(&led7);
    led_turn_off(&led8); 
    __delay_ms(250);
    led_turn_off(&led1);
    led_turn_on(&led2);
    led_turn_off(&led3);
    led_turn_on(&led4);
    led_turn_off(&led5);
    led_turn_on(&led6);
    led_turn_off(&led7);
    led_turn_on(&led8); 
    __delay_ms(250);
   } 
   program_selected =0;
}
 
int main() {
    application_intialize();

    while(1){
        ret = button_read_state(&btn_high,&btn_high_status);
        ret = button_read_state(&btn_low,&btn_low_status);
        
        if(BUTTON_PRESSED == btn_high_status){
            btn_high_valid++;
            if(btn_high_valid > 500){
                btn_high_valid_status = BUTTON_PRESSED;
            }
        }else{
            btn_high_valid = 0;
            btn_high_valid_status = BUTTON_RELEASED;

        }if(btn_high_valid_status !=btn_high_last_valid_status){
            btn_high_last_valid_status =btn_high_valid_status;
            if(btn_high_valid_status ==BUTTON_PRESSED){
                program_selected++;
                switch(program_selected){
            case 1 : program_1();break;
            case 2 : program_2();break;
            case 3 : program_3();break;
            case 4 : program_4();break;
            }
        }  
        }
          if(BUTTON_PRESSED == btn_low_status){
            btn_low_valid++;
            if(btn_low_valid > 500){
                btn_low_valid_status = BUTTON_PRESSED;
            }
        }else{
            btn_low_valid = 0;
            btn_low_valid_status = BUTTON_RELEASED;

        }
        if(btn_low_valid_status !=btn_low_last_valid_status){
            btn_low_last_valid_status =btn_low_valid_status;
            if(btn_low_valid_status ==BUTTON_PRESSED){
                program_selected++;
                switch(program_selected){
            case 1 : program_1();break;
            case 2 : program_2();break;
            case 3 : program_3();break;
            case 4 : program_4();break;
            }
        } 
    }
    }
    return (EXIT_SUCCESS);
    }

void application_intialize(){
    ret = led_intialize(&led1);    
    ret = led_intialize(&led2);  
    ret = led_intialize(&led3);    
    ret = led_intialize(&led4);
    ret = led_intialize(&led5);    
    ret = led_intialize(&led6);
    ret = led_intialize(&led7);    
    ret = led_intialize(&led8);
    ret = button_intialize(&btn_high);
    ret = button_intialize(&btn_low);
}

