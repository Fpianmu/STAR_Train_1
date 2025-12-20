#include "stm32f10x.h"                  // Device header
#include "PWM.h"

void Servo_Init(void)
{
	PWM_Init();
}

void Servo_SetAngleServo(float Angle)
{
	if(Angle < 0) 	Angle = 0;
    if(Angle > 180) Angle = 180;
	PWM_SetCompareServo(Angle / 180 * 2000 + 500);
}

