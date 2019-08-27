#include "hal_timx.h"
#include "hal_sys.h"

TIMx_TypeDef Timx_Structure;


void TIM3_Init(void)
{	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	
	TIMx_Common_Config(TIM3,2000,18000-1,0,TIM_CounterMode_Up);
	
	NVIC_Common_Config(TIM3_IRQn,0,ENABLE);
	
	TIM_ClearFlag(TIM3,TIM_FLAG_Update);
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
	TIM_Cmd(TIM3,ENABLE);
}

void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update) != RESET)
	{
		TIM_ClearITPendingBit(TIM3,TIM_FLAG_Update);
		Timx_Structure.TIM3_Flag = 1;
	}
}

	



