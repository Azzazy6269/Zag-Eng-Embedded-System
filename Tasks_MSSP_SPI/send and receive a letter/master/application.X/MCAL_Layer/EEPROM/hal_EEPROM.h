/* 
 * File:   hal_EEPROM.h
 * Author: smart
 *
 * Created on 08 July, 2024, 11:34 ?
 */

#ifndef HAL_EEPROM_H
#define	HAL_EEPROM_H

/* Section : Includes */
#include "C:\Program Files\Microchip\MPLABX\v6.20\packs\Microchip\PIC18Fxxxx_DFP\1.6.159\xc8\pic\include\proc\pic18f4620.h"
#include "../Interrupt/Internal_interrupt.h"
#include "../mcal_std_types.h"
/* Section : MACRO Declerations */

/* for EEPGD */
#define ACCESS_EEPROM_PROGRAM_MEMORY        0
#define ACCESS_FLASH_PROGRAM_MEMORY         1

/* for CFGS */
#define ACCESS_FLASH_EEPROM_MEMORY          0
#define ACCESS_CONFIG_REGISTERS             1

/* for WREN */
#define ALLOW_WRITE_CYCLES_FLASH_EEPROM     1
#define INHIBTS_WRITE_CYCLES_FLASH_EEPROM   0

/* for WR */
#define INITIATE_DATA_EEPROM_WRITE_ERASE    1
#define DATA_EEPROM_WRITE_ERASE_COMPLETED   0

/* for RD */
#define INITIATES_DATA_EEPROM_READ          1
#define DONT_INITIATES_DATA_EEPROM_READ     0


/* Section : MACRO Functions Declerations */


/* Section : Data Types Declerations */

/* Section : Function Declerations */
Std_ReturnType Data_EEPROM_WriteByte(uint16 bAdd , uint8 bData);
Std_ReturnType Data_EEPROM_ReadByte(uint16 bAdd , uint8 *bData);

#endif	/* HAL_EEPROM_H */

