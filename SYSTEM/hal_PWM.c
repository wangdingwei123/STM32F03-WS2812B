#include "hal_pwm.h"



uint16_t TimerPeriod = 0; 

void TIM14_PWM_Config(void)
{	
	TIM_OCInitTypeDef TIM_OCInitStruct;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM14,ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB,ENABLE);
	
//	GPIO_Common_Config(GPIOA,GPIO_Pin_4,GPIO_Speed_50MHz,GPIO_Mode_AF,GPIO_OType_PP,GPIO_PuPd_UP);
//	GPIO_PinAFConfig(GPIOA,GPIO_PinSource4,GPIO_AF_4); 
	
	GPIO_Common_Config(GPIOB,GPIO_Pin_1,GPIO_Speed_50MHz,GPIO_Mode_AF,GPIO_OType_PP,GPIO_PuPd_UP);
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource1,GPIO_AF_4); 
	
	TIM_DeInit(TIM14);	
	
	TimerPeriod = (SystemCoreClock / 10000) -1; //7200 - 1
/*
		定时时间计算公式：T = (TIM_Period + 1) * (TIM_Prescaler + 1 )/(2 * TIMxCLK)
		  								 = (999 + 1) * (17 + 1) /(2 * 9Mhz) = 1ms
	*/		
	TIMx_Common_Config(TIM14,200-1,4800-1,TIM_CKD_DIV1,TIM_CounterMode_Up);

	/*Channel 1 Configuration in PWM mode  PA4*/
	TIM_OCInitStruct.TIM_OCMode 			= TIM_OCMode_PWM1;
	TIM_OCInitStruct.TIM_OutputState 	= TIM_OutputState_Enable;
	TIM_OCInitStruct.TIM_OutputNState = TIM_OutputNState_Enable; 
	TIM_OCInitStruct.TIM_OCPolarity 	= TIM_OCPolarity_Low;
	TIM_OCInitStruct.TIM_OCNPolarity 	= TIM_OCNPolarity_High;
	TIM_OCInitStruct.TIM_OCIdleState 	= TIM_OCIdleState_Set;
	TIM_OCInitStruct.TIM_OCNIdleState = TIM_OCNIdleState_Reset;
	TIM_OC1Init(TIM14,&TIM_OCInitStruct);  
	 
	PWM_OutputVlot(TIM14,3300);
	
	TIM_CtrlPWMOutputs(TIM14,ENABLE);
	TIM_Cmd(TIM14,ENABLE); 
}


void  PWM_OutputVlot(TIM_TypeDef * TIMx,uint16_t dutyfactor)
{
	uint32_t Channel1Pulse;
	Channel1Pulse = (uint16_t) (((uint32_t) dutyfactor * (TimerPeriod - 1)) / 3300);	//IO 输出 0~3300mV

	TIMx->CCR1 = Channel1Pulse;
 
}


