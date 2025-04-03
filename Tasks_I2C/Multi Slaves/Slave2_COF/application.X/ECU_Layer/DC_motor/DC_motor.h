/* 
 * File:   DC_motor.h
 * Author: moham
 *
 * Created on May 8, 2024, 6:42 PM
 */

#ifndef DC_MOTOR_H
#define	DC_MOTOR_H

/* Section : Includes */
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "ECU_DC_motor_cfg.h"

/* Section : MACRO Declerations */
#define DC_MOTOR_ON_STATUS    0x01U
#define DC_MOTOR_OFF_STATUS   0x00U

#define DC_MOTOR_PIN1 0x00U
#define DC_MOTOR_PIN2 0X01U
/* Section : MACRO Functions Declerations */


/* Section : Data Types Declerations */
typedef struct {
    pin_config_t dc_motor_pin[2];
}dc_motor_t;         //describe both tow pins

/* Section : software interface Declerations */
Std_ReturnType dc_motor_intialize (const dc_motor_t * _dc_motor);
Std_ReturnType dc_motor_turn_right (const dc_motor_t * _dc_motor);
Std_ReturnType dc_motor_turn_left (const dc_motor_t * _dc_motor);
Std_ReturnType dc_motor_stop (const dc_motor_t * _dc_motor);



#endif	/* DC_MOTOR_H */

