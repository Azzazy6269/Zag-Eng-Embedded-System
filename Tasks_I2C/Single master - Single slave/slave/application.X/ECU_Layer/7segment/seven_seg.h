/* 
 * File:   seven_seg.h
 * Author: moham
 *
 * Created on May 9, 2024, 10:46 PM
 */

#ifndef SEVEN_SEG_H
#define	SEVEN_SEG_H

/* Section : Includes */
#include "ECU_seven_seg_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/* Section : MACRO Declerations */


/* Section : MACRO Functions Declerations */


/* Section : Data Types Declerations */
typedef enum{
    SEGMENT_COMMON_ANODE,
    SEGMENT_COMMON_CATHODE
}segment_type_t;

typedef struct{
    pin_config_t segment_pins[4];
    segment_type_t segment_type;
}segment_t;
/* Section : Function Declerations */
Std_ReturnType seven_segment_intialize(const segment_t *seg);
Std_ReturnType seven_segment_write_number(const segment_t *seg,uint8 number);


#endif	/* SEVEN_SEG_H */

