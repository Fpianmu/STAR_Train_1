#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"

int main(void)
{
	LED_Init();    //LED 板载PC13的GPIO初始化
	Delay_init(72);   //延迟等待函数初始化
	while(1)
	{
		LED_ON();   //亮起 （拉高电平）
		Delay_ms(1000);
		LED_OFF();  //熄灭（拉低电平）
		Delay_ms(1000);
	}
	
}
