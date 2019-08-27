#ifndef __HAL_SYS_H
#define __HAL_SYS_H

#include "stm32f0xx.h" 
#include "math.h"
#include "stdio.h"
#include "string.h"


#ifndef BIT
#define BIT(x)  (1 << (x) )
#endif 

#define  	u8			uint8_t  
#define   u16			uint16_t  
#define   u32 		uint32_t


#include  "hal_delay.h"



/* 通用定义------------------------------------------------------------------*/
/**
功能描述：使用结构体的位段操作，可以实现位操作
*/
typedef struct _16_Bis_struct
{
	u16 bit0 : 1;
	u16 bit1 : 1;
	u16 bit2 : 1;
	u16 bit3 : 1;
	u16 bit4 : 1;
	u16 bit5 : 1;
	u16 bit6 : 1;
	u16 bit7 : 1;
	u16 bit8 : 1;
	u16 bit9 : 1;
	u16 bit10 : 1;
	u16 bit11 : 1;
	u16 bit12 : 1;
	u16 bit13 : 1;
	u16 bit14 : 1;
	u16 bit15 : 1;	
}Bits_16_TypeDef;


#define PAout						((Bits_16_TypeDef*)(&GPIOA->ODR))
#define PAin						((Bits_16_TypeDef*)(&GPIOA->IDR))


#define PBout						((Bits_16_TypeDef*)(&GPIOB->ODR))
#define PBin						((Bits_16_TypeDef*)(&GPIOB->IDR))


#define PCout						((Bits_16_TypeDef*)(&GPIOC->ODR))
#define PCin						((Bits_16_TypeDef*)(&GPIOC->IDR))

#define PDout						((Bits_16_TypeDef*)(&GPIOD->ODR))
#define PDin						((Bits_16_TypeDef*)(&GPIOD->IDR))


#define PEout						((Bits_16_TypeDef*)(&GPIOE->ODR))
#define PEin						((Bits_16_TypeDef*)(&GPIOE->IDR))


#define PFout						((Bits_16_TypeDef*)(&GPIOF->ODR))
#define PFin						((Bits_16_TypeDef*)(&GPIOF->IDR))










enum{YES,NO};
enum{OFF,ON};

typedef enum {FALSE = 0,TRUE = !FALSE}bool;






void GPIO_Common_Config(GPIO_TypeDef *GPIOx,uint16_t Pinx,GPIOSpeed_TypeDef Speed,GPIOMode_TypeDef Mode,GPIOOType_TypeDef OType,GPIOPuPd_TypeDef PuPd);
void TIMx_Common_Config(TIM_TypeDef* TIMx,uint32_t Period,uint16_t Prescaler,uint16_t Clock,uint16_t Mode);
void NVIC_Common_Config(uint8_t IRQn,uint8_t Priority, FunctionalState Cmd);
void PWM_Common_Config(TIM_TypeDef* TIMx,uint16_t Mode,uint16_t OutputState,uint16_t OutputNState,uint16_t Pulse,uint16_t OCPolarity,uint16_t OCNPolarity,\
											 uint16_t OCIdleState,uint16_t OCNIdleState);

#endif 
