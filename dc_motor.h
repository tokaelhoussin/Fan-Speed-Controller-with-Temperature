/*
 * dc_motor.h
 *
 *  Created on: Oct 19, 2021
 *      Author: as
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include "std_types.h"
enum STATE
{
	stop,CW, ACW
};
typedef uint8 DcMotor_State;
void DcMotor_Init(void);

void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DC_MOTOR_H_ */
