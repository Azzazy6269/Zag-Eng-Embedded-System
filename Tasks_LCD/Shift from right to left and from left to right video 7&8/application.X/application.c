/* 
 * File:   application.c
 * Author: moham
 *
 * Created on April 22, 2024, 5:52 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "application.h"


int main() {
Std_ReturnType ret=E_NOT_OK;
uint8 lcd1_counter=ZERO_INIT;
application_intialize();
ret =lcd_8bit_send_string_pos(&lcd2,1,1,"Loading");
ret =lcd_8bit_send_string_pos(&lcd2,1,1,"Embedded diploma");
while(1){
    for(lcd1_counter=5;lcd1_counter<=7;++lcd1_counter){
        ret = lcd_4bit_send_string_pos(&lcd1,1,lcd1_counter,"Hello All");
        __delay_ms(250);
        ret = lcd_4bit_send_char_data_pos(&lcd1,1,lcd1_counter,' ');
    }
    ret = lcd_4bit_send_string_pos(&lcd1,1,5,"            ");
     for(lcd1_counter=7;lcd1_counter>=5;--lcd1_counter){
        ret = lcd_4bit_send_string_pos(&lcd1,1,lcd1_counter,"Hello All");
        __delay_ms(250);
        ret = lcd_4bit_send_char_data_pos(&lcd1,1,lcd1_counter+8,' ');
    }
}
    return (EXIT_SUCCESS);
}

void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK ;
    ret = lcd_4bit_intialize(&lcd1);
    ret = lcd_8bit_intialize(&lcd2);
}