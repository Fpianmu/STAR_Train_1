#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Key.h"
#include "OLED.h"
#include "Timer.h"
#include "Servo.h"

int main(void)
{
	OLED_Init();
	Key_Init();
	Timer_Init();
	
	
	while (1)
	{
		
		if (Key_Check(KEY_1, KEY_SINGLE)) //µ¥»÷
		{
			Servo_SetAngle(90);
		}
		if (Key_Check(KEY_1, KEY_DOUBLE)) //Ë«»÷
		{
			Servo_SetAngle(180);
		}
		
		if (Key_Check(KEY_1, KEY_LONG))  //³¤°´
		{
			Servo_SetAngle(0);
			Delay_ms(500);
			Servo_SetAngle(90);
			Delay_ms(500);
			Servo_SetAngle(180);
		}
		
		
	}
}

void TIM2_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
	{
		Key_Tick();
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}
