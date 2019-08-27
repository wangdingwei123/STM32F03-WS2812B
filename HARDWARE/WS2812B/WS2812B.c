#include "ws2812B.h"


/**
	* @brief   WS2812B -- ��������ɫ��
	* @param 	
	* @retval
	* ����PA5������
	*/
void WS2812B_GPIO_Init(void)
{
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA,ENABLE);
	
	GPIO_Common_Config(GPIOA,GPIO_Pin_5|GPIO_Pin_4,GPIO_Speed_50MHz,GPIO_Mode_OUT,GPIO_OType_PP,GPIO_PuPd_NOPULL);	
	
}
/**
	* @brief   WS2812B -- ��������ɫ��
	* @param 	
	* @retval
	* ����PA5������
	*/
void RGB_LED_Write0(void)
{
	RGB_LED_HIGH;
	__nop();__nop();__nop();__nop();__nop();__nop();
	RGB_LED_LOW;
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();
}
/**
	* @brief   WS2812B -- ��������ɫ��
	* @param 	
	* @retval
	* ����PA5������
	*/
void RGB_LED_Write1(void)
{
	RGB_LED_HIGH;
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();
	RGB_LED_LOW;
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();
	
}
/**
	* @brief   WS2812B -- ��������ɫ��
	* @param 	
	* @retval
	* ����PA5������
	*/
void RGB_LED_Reset(void)
{
	RGB_LED_LOW;
	delay_us(80);
}
/**
	* @brief   WS2812B -- ��������ɫ��
	* @param 	 byte д��8λ����
	* @retval
	* ����PA5������
	*/
void RGB_LED_Write_Byte(uint8_t byte)
{
	uint8_t i;
	for(i=0;i<8;i++)
	{
		if(byte&0x80)
			RGB_LED_Write1();
		else 
			RGB_LED_Write0();
		byte <<=1;
	}
}
/**
	* @brief   WS2812B -- ��������ɫ��
	* @param[i] green	 ��ɫ
	* @param[i] red		 ��ɫ
	* @param[i] blue   ��ɫ
	* @retval
	* ����PA5������
	*/
void RGB_LED_Write_24Bits(uint8_t green ,uint8_t red,uint8_t blue)
{
	RGB_LED_Write_Byte(green);
	RGB_LED_Write_Byte(red);
	RGB_LED_Write_Byte(blue);
}
/**
	* @brief   WS2812B -- ��������ɫ��
	* @param[i] green	 ��ɫ
	* @param[i] red		 ��ɫ
	* @param[i] blue   ��ɫ
	* @retval
	* ����PA5������
	*/
void RGB_LED_Write_8word(uint8_t green,uint8_t red,uint8_t blue)
{
	uint8_t i;
	for(i=0;i<8;i++)
	{
		RGB_LED_Write_24Bits(green,red,blue);
	}
}




