#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Timer.h"
#include "LED.h"

uint16_t Num;

int main(void)
{
	OLED_Init();
	Timer_Init();	
	LED_Init();
	while (1)
	{
		OLED_ShowNum(1,1,Num,5);
		if (Num%2 == 0)
		{
			LED_ON();
		}
		else
		{
			LED_OFF();
		}
	}
}

void TIM2_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
	{
		Num ++;
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}
