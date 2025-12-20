#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include <stdio.h>
#include "OLED.h"
#include "PWM.h"
#include "Servo.h"
#include "Serial.h"

float angle;

int main(void)
{
	OLED_Init();
	Serial_Init();
	Servo_Init();
	//输入格式： FF 3a 3b 3c FE   舵机角度设置为100*a+10*b+c
	while (1)
	{
		if (Serial_GetRxFlag())
		{
			uint8_t num1,num2,num3;
			num1 = (Serial_RxPacket[0]-'0')*100;
			num2 = (Serial_RxPacket[1]-'0')*10;
			num3 = (Serial_RxPacket[2]-'0')*1;
			angle = (float)(num1+num2+num3);
			OLED_ShowNum(1,1,(uint32_t)angle,5);
			Servo_SetAngleServo(angle);
		}
	}
	
}
