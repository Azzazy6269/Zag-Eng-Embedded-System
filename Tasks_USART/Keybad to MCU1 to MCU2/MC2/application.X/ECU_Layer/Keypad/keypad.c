/* 
 * File:   keypad.c
 * Author: moham
 *
 * Created on May 11, 2024, 9:15 PM
 */
#include "keypad.h"
#define _XTAL_FREQ (uint64)3200000

static const uint8 btn_values[ECU_KEYPAD_ROWS][ECU_KEYPAD_COLUMNS]={
    {'7','8','9','/'},
    {'4','5','6','*'},
    {'1','2','3','-'},
    {'%','0','=','+'}
};

/**
 * @breif intialize the keypad
 * @param _keypad_obj
 * @return status of the function
 *          E_OK :the function done successfully
 *          E_NOT_OK :the function had an issue while performing the action
 */
Std_ReturnType keypad_intialize(const keypad_t *_keypad_obj){
    Std_ReturnType ret = E_OK ;
    uint8 rows_counter =ZERO_INIT;
    uint8 columns_counter =ZERO_INIT;
     if(NULL==_keypad_obj){
             ret = E_NOT_OK;

     }else{
       for(rows_counter=ZERO_INIT;rows_counter<ECU_KEYPAD_ROWS;rows_counter++){
           ret = gpio_pin_intialize(&(_keypad_obj->keypad_row_pins[rows_counter]));
       }
              for(columns_counter=ZERO_INIT;columns_counter<ECU_KEYPAD_COLUMNS;columns_counter++){
           ret = gpio_pin_direction_intialize(&(_keypad_obj->keypad_columns_pins[columns_counter]));

        }
     }
     return E_OK;
}

/**
 * @breif get the value from the keypad
 * @param _keypad_obj
 * @return status of the function
 *          E_OK :the function done successfully
 *          E_NOT_OK :the function had an issue while performing the action
 */
Std_ReturnType keypad_get_value(const keypad_t *_keypad_obj,uint8 *value){
    Std_ReturnType ret = E_OK ;
    uint8 rows_counter = ZERO_INIT , columns_counter = ZERO_INIT , counter = ZERO_INIT;
    uint8 column_logic = ZERO_INIT;
     if((NULL==_keypad_obj)||(NULL==value)){
             ret = E_NOT_OK;
     }else{
       for(rows_counter=ZERO_INIT;rows_counter<ECU_KEYPAD_ROWS;rows_counter++){
           for(counter=ZERO_INIT;counter<ECU_KEYPAD_ROWS;counter++){
               gpio_pin_write_logic(&(_keypad_obj->keypad_row_pins[counter]),GPIO_LOW);
           }
           gpio_pin_write_logic(&(_keypad_obj->keypad_row_pins[rows_counter]),GPIO_HIGH);
           for(columns_counter=ZERO_INIT;columns_counter<ECU_KEYPAD_COLUMNS;columns_counter++){
              ret = gpio_pin_read_logic(&(_keypad_obj->keypad_columns_pins[columns_counter]),&column_logic);
              if(column_logic==GPIO_HIGH){
                  *value =btn_values[rows_counter][columns_counter];
              }
           }
       } 
     }
     return E_OK;
}