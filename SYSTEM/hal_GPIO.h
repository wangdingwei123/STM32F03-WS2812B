#ifndef __HAL_GPIO_H
#define __HAL_GPIO_H

#include "hal_sys.h"



#define LED_OFF		GPIOA->BSRR = 1 << 4
#define LED_ON    GPIOA->BRR  = 1 << 4


void GPIO_CommonConfig(void);
#endif 

