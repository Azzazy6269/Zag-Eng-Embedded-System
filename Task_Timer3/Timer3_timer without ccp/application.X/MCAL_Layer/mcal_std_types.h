/* 
 * File:   mcal_std_types.h
 * Author: moham
 *
 * Created on April 22, 2024, 5:27 PM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

/* Section Includes */
#include "std_libraries.h"


/* Section : Data Types Declerations */
typedef unsigned char           uint8  ;
typedef unsigned short          uint16 ;
typedef unsigned int            uint32 ;
typedef unsigned long long      uint64 ;
typedef signed char             sint8  ;
typedef signed int              sint32 ;
typedef signed short            sint16 ;
typedef uint8           Std_ReturnType ;

/* Section : MACRO Declerations */
#define STD_HIGH        0x01
#define STD_LOW         0x00

#define CONFIG_ENABLE   0x01
#define CONFIG_DISABLE  0x00

#define STD_ON          0x01
#define STD_OFF         0x00

#define STD_ACTIVE      0x01
#define STD_IDLE        0x00

#define E_OK           (Std_ReturnType)0x01
#define E_NOT_OK       (Std_ReturnType)0x00

#define ZERO_INIT       0




#define _XTAL_FREQ (uint64)8000000




/* Section : MACRO Functions Declerations */
/* Section : Function Declerations */
#endif	/* MCAL_STD_TYPES_H */

