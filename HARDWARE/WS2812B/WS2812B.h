#ifndef __WS2812B_H
#define __WS2812B_H
#include "hal_sys.h"



#define RGB_LED_HIGH		PAout->bit5 = 1
#define RGB_LED_LOW			PAout->bit5 = 0


void WS2812B_GPIO_Init(void);

void RGB_LED_Write_8word(uint8_t green,uint8_t red,uint8_t blue);

#endif 

