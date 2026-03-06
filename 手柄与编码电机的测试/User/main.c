#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "ps2.h"
#include "PWM.h"
#include "Servo.h"
#include "Motor.h"
#include "Encoder.h"

unsigned char Key_Pressed = 0;   //手柄按键是否按下的判断
unsigned char mode = PSB_LOSE;  //手柄模式
unsigned char lx,ly,rx,ry;  //两个摇杆的x,y方向数值记录

void System_Init()
{
	//取消抢占优先级  分为16级子优先级
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
	//手柄初始化
	PS2_Init();   
	
	//电机，舵机初始化
	Engine_Init(); 
	
	//OLED屏幕初始化
	OLED_Init();
	OLED_Clear();
	
	//编码器初始化
	Encoder_Init();
}
int main(void)
{
	System_Init();
	while(1)
	{
		int64_t pos_r2 = Encoder_GetPos_l2();
		OLED_ShowNum(5,5,pos_r2,5);
		Move(60);
//		PS2_ReadData();  //接收器接收信息
//        mode = ps2_mode_get(); //获取手柄模式
//		if (mode == PSB_REDLIGHT_MODE)
//		{
//			lx = ps2_get_anolog_data(PSS_LX);
//            ly = ps2_get_anolog_data(PSS_LY);
//            rx = ps2_get_anolog_data(PSS_RX);
//            ry = ps2_get_anolog_data(PSS_RY);
//			Key_Pressed = ps2_key_serch();  //判断按键是否按下
////			OLED_ShowNum(5,5,lx,3);
////			OLED_ShowNum(6,5,ly,3);
////			OLED_ShowNum(7,5,rx,3);
////			OLED_ShowNum(8,5,ry,3);
//			Servo_SetAngle(lx*180/255);
//		}
	}
	
}
