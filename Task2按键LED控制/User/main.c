#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "Key.h"

uint8_t KeyNum;

int main(void)
{
	LED_Init();    //LED 板载PC13的GPIO初始化
	Delay_init(72);   //延迟等待函数初始化
	Key_Init();   //按键初始化
	LED_OFF();
	while(1)
	{
		KeyNum = Key_GetNum();
		if (Flag)
		{
			LED_Turn();   //亮灭转换
		}
	}
	
}
