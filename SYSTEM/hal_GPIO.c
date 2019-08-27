#include "hal_gpio.h"

void GPIO_CommonConfig(void)
{ 
	RCC->AHBENR  |= 1 << 17;							//IO�˿�Aʹ��
	GPIOA->MODER &= ~(0x03 << (4 * 2));	//���
	GPIOA->MODER |= (0x01 << (4 * 2));	//0x01 = ���ģʽ�� 4 = ����  ģʽռ2λ
	
	GPIOA->OSPEEDR &= ~(0x03 <<(4 * 2));//�������
	GPIOA->OSPEEDR |= (0x00 <<(4 * 2)); //0x00 = 10M ���٣� 4 = ����  ģʽռ2λ
	
	GPIOA->OTYPER &= ~(0x01 <<(4 ));//�������
	GPIOA->OTYPER |= (0x00 <<(4 )); //0x00 = ��������� 4 = ���� 	
	
	GPIOA->PUPDR &= ~(0x03 <<(4 * 2));//�������/����
	GPIOA->PUPDR |= (0x01 <<(4 * 2)); //0x01 = ���� �� 4 = ����  ģʽռ2λ
	
}





