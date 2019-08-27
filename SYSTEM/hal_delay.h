#ifndef __HAL_DELAY_H
#define __HAL_DELA_H

#include "hal_sys.h"


void  delay_ms(u16 nms);
void  delay_us(u32 nus);
void  Delay_Init(void);

extern  u16 fac_ms;	//全局变量
extern  u8  fac_us;	//全局变量




#endif 
