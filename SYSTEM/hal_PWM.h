#ifndef __HAL_PWM_H
#define __HAL_PWM_H
#include "hal_sys.h"
#include "hal_Timx.h"



typedef struct 
{
	uint16_t TimerPeriod;
	uint16_t Channel1Pulse ;
	uint16_t Channel2Pulse ;
	uint16_t Channel3Pulse ;
	uint16_t Channel4Pulse ;
	TIM_OCInitTypeDef TIM_OCInitStruct;
}PWM_TypeDef;






void TIM14_PWM_Config(void);
void  PWM_OutputVlot(TIM_TypeDef * TIMx,uint16_t dutyfactor);


#endif 

