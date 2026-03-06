#include "stm32f10x.h"                  // Device header
#include "PWM.h"

void Move(int16_t speed)
{
	//范围限制判断
	if (speed > 100 )
	{
		speed = 100;
	}
	if (speed < -100 )
	{
		speed = -100;
	}
	
	//PWM输出
	if (speed > 0)  //前进
	{
		PWM_SetCompare1_T3(speed);
		PWM_SetCompare2_T3(0);
	}
	else if (speed < 0)  //后退
	{
		PWM_SetCompare1_T3(0);
		PWM_SetCompare2_T3(-speed);
	}
	else   //停车
	{
		PWM_SetCompare1_T3(0);
		PWM_SetCompare2_T3(0);
	}
}

