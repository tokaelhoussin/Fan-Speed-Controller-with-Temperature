/*
 * main.c
 *
 *  Created on: Oct 19, 2021
 *      Author: as
 */

#include "avr/io.h"
#include "dc_motor.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "adc.h"

int main(void){
	uint8 temp;
	uint8 speed;
	LCD_init();
	ADC_ConfigType Init;
	Init.prescaler=8;
	Init.ref_volt=2.56;
	ADC_init(&Init);
	DcMotor_Init();
	LCD_moveCursor(0,3);
	LCD_displayString("FAN is ");
	LCD_moveCursor(1,3);
	LCD_displayString("TEMP =    C");
	while(1){
		temp = LM35_getTemperature();
		speed=(float)temp*100/120;
		if(speed<25){
			DcMotor_Rotate(stop,0);
			LCD_moveCursor(0,10);
			LCD_displayString("OFF");
		}
		else if((speed>=25)&&(speed<50)){
			DcMotor_Rotate(CW,25);
			LCD_moveCursor(0,10);
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
		}
		else if((speed>=50)&&(speed<75)){
			DcMotor_Rotate(CW,50);
			LCD_moveCursor(0,10);
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
		}
		else if((speed>=75)&&(speed<100)){
			DcMotor_Rotate(CW,75);
			LCD_moveCursor(0,10);
			LCD_displayString("ON");
			LCD_displayCharacter(' ');

		}
		else if(speed>=100){
			DcMotor_Rotate(CW,100);
			LCD_moveCursor(0,10);
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
				}
		LCD_moveCursor(1,10);
		if(temp >= 100)
				{
					LCD_intgerToString(temp);
				}
				else
				{
					LCD_intgerToString(temp);
					/* In case the digital value is two or one digits print space in the next digit place */
					LCD_displayCharacter(' ');
				}
	}
}
