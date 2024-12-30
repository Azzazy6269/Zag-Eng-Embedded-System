/* 
 * File:   hal_EEPROM.c
 * Author: smart
 *
 * Created on 08 July, 2024, 11:34 ?
 */


#include "hal_EEPROM.h"

Std_ReturnType Data_EEPROM_WriteByte(uint16 bAdd , uint8 bData){
    Std_ReturnType ret = E_OK ;
    /* Read the Interrupt Status "Enabled or Disabled" */
       uint8 Global_Interrupt_status = INTCONbits.GIE;
    /* Update the Address Registers */
       EEADRH = (uint8)((bAdd >> 8) & 0x03);
       EEADR  = (uint8) (bAdd & 0xFF);
    /* Update the Data Registers */
       EEDATA = bData;
    /* Select Access data EEPROM memory */
       EECON1bits.EEPGD = ACCESS_EEPROM_PROGRAM_MEMORY;
       EECON1bits.CFGS  = ACCESS_FLASH_EEPROM_MEMORY;
    /* Allows write cycles to Flash program/data EEPROM */
       EECON1bits.WREN  = ALLOW_WRITE_CYCLES_FLASH_EEPROM;
    /* Disable all interrupt "General Interrupt" */
       INTERRUPT_GlobalInturreptEnable() ;
    /* Write the required sequence : 0x55 -> 0xAA */
       EECON2 = 0x55;
       EECON2 = 0xAA;  
    /* Initiates a data EEPROM erase/write cycle */
       EECON1bits.WR = INITIATE_DATA_EEPROM_WRITE_ERASE; 
    /* Wait for write to complete */
       while(EECON1bits.WR);
    /* Inhibits write cycles to Flash program/data EEPROM */
       EECON1bits.WREN =INHIBTS_WRITE_CYCLES_FLASH_EEPROM;
    /* Restore the Interrupt Status "Enabled or Disabled" */
       INTCONbits.GIE = Global_Interrupt_status;
    return ret ;
}

Std_ReturnType Data_EEPROM_ReadByte(uint16 bAdd , uint8 *bData){
    Std_ReturnType ret = E_OK ;
    if(NULL == bData){
        ret = E_NOT_OK ;
    }else{
        /* Update the Address Registers */
        EEADRH = (uint8)((bAdd >> 8) & 0x03);
        EEADR  = (uint8) (bAdd & 0xFF);
        /* Select Access data EEPROM memory */
        EECON1bits.EEPGD = ACCESS_EEPROM_PROGRAM_MEMORY;
        EECON1bits.CFGS  = ACCESS_FLASH_EEPROM_MEMORY;
        /* Initiates a data EEPROM erase/write cycle */
        EECON1bits.RD = INITIATES_DATA_EEPROM_READ; 
        /* Return data */
        *bData = EEDATA ;
    }
    return ret ;
}