#include "stm32f10x.h"

void PWM_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 | RCC_APB1Periph_TIM3 | RCC_APB1Periph_TIM4, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1 | RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);

    //GPIO初始化
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    //TIM1 PWM引脚
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8  | GPIO_Pin_11;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    

    
	//TIM1配置
    TIM_InternalClockConfig(TIM1);
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    TIM_TimeBaseInitStructure.TIM_Period = 20000 - 1;        // ARR
    TIM_TimeBaseInitStructure.TIM_Prescaler = 72 - 1;      // PSC
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM1, &TIM_TimeBaseInitStructure);
	
    TIM_OCInitTypeDef TIM_OCInitStructure;
    TIM_OCStructInit(&TIM_OCInitStructure);
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;   //设置空闲状态
    TIM_OCInitStructure.TIM_Pulse = 0;
	
	TIM_OC1Init(TIM1, &TIM_OCInitStructure);   //PA8     
    TIM_OC4Init(TIM1, &TIM_OCInitStructure);  // PA11 
    
	TIM_BDTRInitTypeDef TIM_BDTRInitStructure;
	TIM_BDTRInitStructure.TIM_OSSRState = TIM_OSSRState_Enable;          // 运行模式输出使能
	TIM_BDTRInitStructure.TIM_OSSIState = TIM_OSSIState_Enable;          // 空闲模式输出使能  
	TIM_BDTRInitStructure.TIM_LOCKLevel = TIM_LOCKLevel_OFF;             // 无锁定
	TIM_BDTRInitStructure.TIM_DeadTime = 0;                              // 无死区时间（单路输出不需要）
	TIM_BDTRInitStructure.TIM_Break = TIM_Break_Disable;                 // 禁用刹车功能
	TIM_BDTRInitStructure.TIM_BreakPolarity = TIM_BreakPolarity_Low;     // 刹车极性（随意设置，因为已禁用）
	TIM_BDTRInitStructure.TIM_AutomaticOutput = TIM_AutomaticOutput_Enable;  // 自动输出使能

	TIM_BDTRConfig(TIM1, &TIM_BDTRInitStructure);
    
	TIM_CtrlPWMOutputs(TIM1, ENABLE);    //高级定时器必须使能主输出   先
	TIM_Cmd(TIM1, ENABLE);     //后   注意先后顺序
	
}
void PWM_SetCompareServo(uint16_t Compare)     //PA11
{
	if(Compare < 500) 	Compare = 500;     //脉冲宽度范围为500-2500（0.5ms-2.5ms）
    if(Compare > 2500) 	Compare = 2500;
	TIM_SetCompare4(TIM1, Compare);
}
