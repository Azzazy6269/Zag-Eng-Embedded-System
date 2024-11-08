/* 
 * File:   application.c
 * Author: moham
 *
 * Created on April 22, 2024, 5:52 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "application.h"

void welcome_message(void){
    uint8 lcd1_counter=ZERO_INIT;
    for(lcd1_counter=1;lcd1_counter<=5;++lcd1_counter){
        lcd_4bit_send_string_pos(&lcd1,1,7,"Hello All");
        lcd_4bit_send_string_pos(&lcd1,2,3,"Embedded Diploma");
        __delay_ms(500);
        lcd_4bit_send_command(&lcd1,_LCD_CLEAR);
        __delay_ms(100);
    }
}

void loading_screen(void){
    lcd_8bit_send_string_pos(&lcd2,1,1,"Loading");
    uint8 l_lcd2_counter =ZERO_INIT;
    for(l_lcd2_counter=8;l_lcd2_counter<=15;++l_lcd2_counter){
        lcd_8bit_send_char_data_pos(&lcd2,1,l_lcd2_counter,'.');
        __delay_ms(150);
    }
    lcd_8bit_send_string_pos(&lcd2,1,8,"              ");
    __delay_ms(150);
}



int main() {
Std_ReturnType ret=E_NOT_OK;
application_intialize();
welcome_message();
while(1){
 loading_screen();
    }

    return (EXIT_SUCCESS);
}

void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK ;
    ret = lcd_4bit_intialize(&lcd1);
    ret = lcd_8bit_intialize(&lcd2);
}