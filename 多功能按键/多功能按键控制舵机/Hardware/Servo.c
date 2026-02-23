#include "stm32f10x.h"                  // Device header
#include "Timer.h"

void Servo_SetAngle(float Angle)
{
	PWM_SetCompare1_T4(Angle * 2000 / 180+ 500);
}
