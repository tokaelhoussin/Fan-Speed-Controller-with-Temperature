/*
 * dc_motor.c
 *
 *  Created on: Oct 19, 2021
 *      Author: as
 */


#include "avr/io.h"
#include "dc_motor.h"
#include "gpio.h"
#include "common_macros.h"
#include "pwm.h"

	void DcMotor_Init(void){
		/* configure pin PB0 and PB1 as output pins */
		DDRB|=0x03;
		/* Motor is stop at the beginning */
		PORTB &= 0xFC;
	}
	void DcMotor_Rotate(DcMotor_State state,uint8 speed){
		PWM_Timer0_Start(speed);
		if(state==CW)
				{
					// Rotate the motor --> clock wise
					PORTB &= (~(1<<PB0));
					PORTB |= (1<<PB1);
				}

				/* check if the second push button at PA1 is pressed/not */
		else if(state==ACW)
				{
					// Rotate the motor --> anti-clock wise
					PORTB |= (1<<PB0);
					PORTB &= (~(1<<PB1));
				}

				/* check if the third push button at PA2 is pressed/not */
		else if(state==stop)
				{
					// Stop the motor
					PORTB &= (~(1<<PB0));
					PORTB &= (~(1<<PB1));
				}
	}

