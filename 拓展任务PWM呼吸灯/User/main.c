#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "Key.h"
#include "PWM.h"
#include "OLED.h"


int main(void)
{
	Delay_init(72);   //延迟等待函数初始化
	OLED_Init();
	PWM_Init();
	while(1)
	{
		for (int i=0;i<=100;i++)
		{
			PWM_SetCompare1(i);
			Delay_ms(10);
		}
		for (int i=100;i>=0;i--)
		{
			PWM_SetCompare1(i);
			Delay_ms(10);
		}
	}
	
}
