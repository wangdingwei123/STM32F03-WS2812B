#include "stm32f0xx.h"
#include "hal_GPIO.h"
#include "hal_sys.h"
#include "hal_pwm.h"
#include "ws2812B.h"

	uint8_t red = 0;
	uint8_t green = 0;
	uint8_t blue = 0;
	uint8_t data = 0;
int main(void)
{
	Delay_Init(); 
	TIM14_PWM_Config();
	WS2812B_GPIO_Init();
	while(1)
	{ 
		
		if(data == 0)	// ∫Ï¬Ã¿∂
		{
			if(red < 255)
			red++;
			else if(red == 255 && blue == 0)
				green++;
			if(green == 255)
			{
				blue++;
			}
			if(blue == 255)
			{
				blue = 0;
				green = 0;
				red = 0;
				data = 1;
			}
		}else if(data == 1)//∫Ï¿∂¬Ã
		{
			
			if(red < 255)
			red++;
			else if(red == 255 && green == 0)
				blue++;
			if(blue == 255)
			{
				green++;
			}
			if(green == 255)
			{
				blue = 0;
				green = 0;
				red = 0;
				data = 2;
			}
		}else if(data == 2)//¿∂¬Ã∫Ï
		{
			
			if(blue < 255)
			blue++;
			else if(blue == 255 && red == 0)
				green++;
			if(green == 255)
			{
				red++;
			}
			if(red == 255)
			{
				blue = 165;
				green = 165;
				red = 165;
				data = 3;
			}
		}else if(data == 3)
		{
			blue +=2;
			red +=2;
			green +=1;
			if(green == 255)
			{
				data = 4;
				green = 0;
				red = 0;
				blue = 0;
			}
		}else if(data == 4)
		{
			if(blue < 255)
			{
				blue ++;
			}else 
			{
				red++;
			}
			if(red == 255)
			{
				blue = 0;
				red = 0;
				data = 0;
			}
		}
		PAout->bit4 =~PAout->bit4;
		RGB_LED_Write_8word(green,red,blue);
		delay_ms(10);
	}
}

