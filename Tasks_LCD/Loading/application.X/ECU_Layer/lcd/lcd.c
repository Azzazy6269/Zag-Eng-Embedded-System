/* 
 * File:   lcd.c
 * Author: moham
 *
 * Created on June 24, 2024, 1:15 PM
 */
#include "lcd.h"


static Std_ReturnType lcd_send_4bits(const chr_lcd_4bits_t *lcd,uint8 _data_command);
static Std_ReturnType lcd_4bit_send_enable_signal(const chr_lcd_4bits_t *lcd);
static Std_ReturnType lcd_4bit_set_cursor(const chr_lcd_4bits_t *lcd,uint8 row, uint8 column);
static Std_ReturnType lcd_8bit_send_enable_signal(const chr_lcd_8bits_t *lcd);
static Std_ReturnType lcd_8bit_set_cursor(const chr_lcd_8bits_t *lcd,uint8 row, uint8 column);



Std_ReturnType lcd_4bit_intialize(const chr_lcd_4bits_t * lcd){
   Std_ReturnType ret = E_OK ;
   uint8 l_data_pins_counter= ZERO_INIT;
     if(NULL==lcd){
            ret = E_NOT_OK;
     }else{
        ret = gpio_pin_intialize(&(lcd->lcd_rs));
        ret = gpio_pin_intialize(&(lcd->lcd_en));
        for(l_data_pins_counter;l_data_pins_counter<4;l_data_pins_counter++){
            ret = gpio_pin_intialize(&(lcd->lcd_data[l_data_pins_counter]));
        }
        __delay_ms(20);
        ret = lcd_4bit_send_command(lcd,_LCD_8BIT_MODE_2_LINE);
        __delay_ms(5);
        ret = lcd_4bit_send_command(lcd,_LCD_8BIT_MODE_2_LINE);
        __delay_us(150);
        ret = lcd_4bit_send_command(lcd,_LCD_8BIT_MODE_2_LINE);
        
        
        ret = lcd_4bit_send_command(lcd,_LCD_CLEAR);
        ret = lcd_4bit_send_command(lcd,_LCD_RETURN_HOME);
        ret = lcd_4bit_send_command(lcd,_LCD_ENTERY_MODE);
        ret = lcd_4bit_send_command(lcd,_LCD_CURSOR_OFF_DISPLAY_ON);
        ret = lcd_4bit_send_command(lcd,_LCD_4BIT_MODE_2_LINE);
        ret = lcd_4bit_send_command(lcd,0x80);
     }
    return ret; 
}
Std_ReturnType lcd_4bit_send_command(const chr_lcd_4bits_t * lcd ,uint8 command){
     Std_ReturnType ret = E_OK ;
     if(NULL==lcd){
            ret = E_NOT_OK;
     }else{
         ret =gpio_pin_write_logic(&(lcd->lcd_rs),GPIO_LOW);//select instruction register
         ret =lcd_send_4bits(lcd,command>>4);//send 4 high significant bits
         ret =lcd_4bit_send_enable_signal(lcd);
         ret =lcd_send_4bits(lcd,command);//send 4 low significant bits
         ret =lcd_4bit_send_enable_signal(lcd);
         
     }
    return ret;  
}
Std_ReturnType lcd_4bit_send_char_data (const chr_lcd_4bits_t * lcd ,uint8 data){
     Std_ReturnType ret = E_OK ;
     if(NULL==lcd){
            ret = E_NOT_OK;
     }else{
         ret =gpio_pin_write_logic(&(lcd->lcd_rs),GPIO_HIGH);//select data register
         ret =lcd_send_4bits(lcd,data>>4);//send 4 high significant bits
         ret =lcd_4bit_send_enable_signal(lcd);
         ret =lcd_send_4bits(lcd,data);//send 4 low significant bits
         ret =lcd_4bit_send_enable_signal(lcd);
     }
    return ret;  
}
Std_ReturnType lcd_4bit_send_char_data_pos(const chr_lcd_4bits_t * lcd,uint8 row,uint8 column ,uint8 data){
      Std_ReturnType ret = E_OK ;
     if(NULL==lcd){
            ret = E_NOT_OK;
     }else{
        ret = lcd_4bit_set_cursor(lcd,row,column);
        ret = lcd_4bit_send_char_data(lcd,data);
     }
    return ret; 
}
Std_ReturnType lcd_4bit_send_string(const chr_lcd_4bits_t * lcd ,uint8 *str){
     Std_ReturnType ret = E_OK ;
     if(NULL==lcd){
            ret = E_NOT_OK;
     }else{
         while(*str){
             ret = lcd_4bit_send_char_data(lcd,*str);
             str++;
     }
    return ret;
}
}
Std_ReturnType lcd_4bit_send_string_pos(const chr_lcd_4bits_t * lcd,uint8 row,uint8 column ,uint8 *str){
     Std_ReturnType ret = E_OK ;
     if(NULL==lcd || NULL==str){
            ret = E_NOT_OK;
     }else{
         ret = lcd_4bit_set_cursor(lcd,row,column);
         while(*str){
             ret = lcd_4bit_send_char_data(lcd,*str);
             str++;
         }
     }
    return ret;  
}
Std_ReturnType lcd_4bit_send_custome_char(const chr_lcd_4bits_t * lcd,uint8 row,uint8 column ,const uint8 _chr[],uint8 mem_pos){
       Std_ReturnType ret = E_OK ;
     if(NULL==lcd){
            ret = E_NOT_OK;
     }else{
         
     }
    return ret;
}

Std_ReturnType lcd_8bit_intialize(const chr_lcd_8bits_t * lcd){
     Std_ReturnType ret = E_OK ;
     uint8 l_data_pins_counter =ZERO_INIT;
     if(NULL==lcd){
            ret = E_NOT_OK;
     }else{
        ret = gpio_pin_intialize(&(lcd->lcd_rs));
        ret = gpio_pin_intialize(&(lcd->lcd_en));
        for(l_data_pins_counter;l_data_pins_counter<8;l_data_pins_counter++){
            ret = gpio_pin_intialize(&(lcd->lcd_data[l_data_pins_counter]));
        }
        __delay_ms(20);
        ret = lcd_8bit_send_command(lcd,_LCD_8BIT_MODE_2_LINE);
        __delay_ms(5);
        ret = lcd_8bit_send_command(lcd,_LCD_8BIT_MODE_2_LINE);
        __delay_us(150);
        ret = lcd_8bit_send_command(lcd,_LCD_8BIT_MODE_2_LINE);
        
        
        ret = lcd_8bit_send_command(lcd,_LCD_CLEAR);
        ret = lcd_8bit_send_command(lcd,_LCD_RETURN_HOME);
        ret = lcd_8bit_send_command(lcd,_LCD_ENTERY_MODE);
        ret = lcd_8bit_send_command(lcd,_LCD_CURSOR_OFF_DISPLAY_ON);
        ret = lcd_8bit_send_command(lcd,_LCD_8BIT_MODE_2_LINE);
        ret = lcd_8bit_send_command(lcd,0x80);

     }
    return ret;
}
Std_ReturnType lcd_8bit_send_command(const chr_lcd_8bits_t * lcd ,uint8 command){
     Std_ReturnType ret = E_OK ;
     uint8 l_pin_counter = ZERO_INIT;
     if(NULL==lcd){
            ret = E_NOT_OK;
     }else{
         ret = gpio_pin_write_logic(&(lcd->lcd_rs),GPIO_LOW);
         for(l_pin_counter;l_pin_counter<8;++l_pin_counter){
             ret = gpio_pin_write_logic(&(lcd->lcd_data[l_pin_counter]),(command >> l_pin_counter)& (uint8)0x01);
         }
         ret = lcd_8bit_send_enable_signal(lcd);
     }
    return ret;  
}
Std_ReturnType lcd_8bit_send_char_data(const chr_lcd_8bits_t * lcd ,uint8 data){
    Std_ReturnType ret = E_OK ;
    uint8 l_pin_counter = ZERO_INIT;
     if(NULL==lcd){
            ret = E_NOT_OK;
     }else{
         ret = gpio_pin_write_logic(&(lcd->lcd_rs),GPIO_HIGH);
         for(l_pin_counter;l_pin_counter<8;l_pin_counter++){
             ret = gpio_pin_write_logic(&(lcd->lcd_data[l_pin_counter]),(data >> l_pin_counter)& (uint8)0x01);
         }
         ret = lcd_8bit_send_enable_signal(lcd);
     }
    return ret;
}
Std_ReturnType lcd_8bit_send_char_data_pos(const chr_lcd_8bits_t * lcd,uint8 row,uint8 column ,uint8 data){
    Std_ReturnType ret = E_OK ;
     if(NULL==lcd){
            ret = E_NOT_OK;
     }else{
         ret = lcd_8bit_set_cursor(lcd,row,column);
         ret = lcd_8bit_send_char_data(lcd,data) ;
     }
    return ret;    
}
Std_ReturnType lcd_8bit_send_string(const chr_lcd_8bits_t * lcd ,uint8 *str){
    Std_ReturnType ret = E_OK ;
     if(NULL==lcd || NULL==str){
            ret = E_NOT_OK;
     }else{
         while(*str){
             ret = lcd_8bit_send_char_data(lcd,*str);
             str++;
         }
     }
    return ret;   
}
Std_ReturnType lcd_8bit_send_string_pos(const chr_lcd_8bits_t * lcd,uint8 row,uint8 column ,uint8 *str){
     Std_ReturnType ret = E_OK ;
     if(NULL==lcd){
            ret = E_NOT_OK;
     }else{
            ret = lcd_8bit_set_cursor(lcd,row,column);
            while(*str){
             ret = lcd_8bit_send_char_data(lcd,*str);
             str++;

     }
    return ret;  
}
}    
Std_ReturnType lcd_8bit_send_custome_char(const chr_lcd_8bits_t * lcd,uint8 row,uint8 column ,const uint8 _chr[],uint8 mem_pos){
     Std_ReturnType ret = E_OK ;
     if(NULL==lcd){
            ret = E_NOT_OK;
     }else{
         
     }
    return ret;
}

static Std_ReturnType lcd_send_4bits(const chr_lcd_4bits_t *lcd,uint8 _data_command){
    Std_ReturnType ret = E_OK ;
     if(NULL==lcd){
            ret = E_NOT_OK;
     }else{
       ret = gpio_pin_write_logic(&(lcd->lcd_data[0]),(_data_command >> 0)& (uint8)0x01);
       ret = gpio_pin_write_logic(&(lcd->lcd_data[1]),(_data_command >> 1)& (uint8)0x01);
       ret = gpio_pin_write_logic(&(lcd->lcd_data[2]),(_data_command >> 2)& (uint8)0x01);
       ret = gpio_pin_write_logic(&(lcd->lcd_data[3]),(_data_command >> 3)& (uint8)0x01);
     }
    return ret;
}
static Std_ReturnType lcd_4bit_send_enable_signal(const chr_lcd_4bits_t *lcd){
    Std_ReturnType ret = E_OK ;
     if(NULL==lcd){
            ret = E_NOT_OK;
     }else{
            ret = gpio_pin_write_logic(&(lcd->lcd_en),GPIO_HIGH);
            __delay_us(1);
            ret = gpio_pin_write_logic(&(lcd->lcd_en),GPIO_LOW);
     }
    return ret;  
}
static Std_ReturnType lcd_8bit_send_enable_signal(const chr_lcd_8bits_t *lcd){
    Std_ReturnType ret = E_OK ;
     if(NULL==lcd){
            ret = E_NOT_OK;
     }else{
            ret = gpio_pin_write_logic(&(lcd->lcd_en),GPIO_HIGH);
            __delay_us(1);
            ret = gpio_pin_write_logic(&(lcd->lcd_en),GPIO_LOW);
     }
    return ret;  
}

static Std_ReturnType lcd_8bit_set_cursor(const chr_lcd_8bits_t *lcd,uint8 row, uint8 column){
    Std_ReturnType ret = E_OK ;
     if(NULL==lcd){
            ret = E_NOT_OK;
     }else{
         column--;
         switch(row){
             case ROW1 : ret=lcd_8bit_send_command(lcd,(0x80 + column));break;
             case ROW2 : ret=lcd_8bit_send_command(lcd,(0xc0 + column));break;
             case ROW3 : ret=lcd_8bit_send_command(lcd,(0x94 + column));break;
             case ROW4 : ret=lcd_8bit_send_command(lcd,(0xd4 + column));break;
             default : ;
         }
     }
    return ret;
}

static Std_ReturnType lcd_4bit_set_cursor(const chr_lcd_4bits_t *lcd,uint8 row, uint8 column){
    Std_ReturnType ret = E_OK ;
     if(NULL==lcd){
            ret = E_NOT_OK;
     }else{
         column--;
         switch(row){
             case ROW1 : ret=lcd_4bit_send_command(lcd,(0x80 + column));break;
             case ROW2 : ret=lcd_4bit_send_command(lcd,(0xc0 + column));break;
             case ROW3 : ret=lcd_4bit_send_command(lcd,(0x94 + column));break;
             case ROW4 : ret=lcd_4bit_send_command(lcd,(0xd4 + column));break;
             default : ;
         }
     }
    return ret;
}

void convert_byte_to_string(uint8 value,uint8 *str){
      
}
void convert_short_to_string(uint16 value,uint8 *str){
      
}
void convert_int_to_string(uint32 value,uint8 *str){
      
}
