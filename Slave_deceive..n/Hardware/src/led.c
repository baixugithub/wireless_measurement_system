#include "led.h"

void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOC, ENABLE);
	GPIO_InitStruct.GPIO_Pin = LED0 | LED1 | LED2 | LED3 | LED4 | LED5 \
	| LED6 | LED7 | LEDALL;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2;
	GPIO_Init(GPIOD, &GPIO_InitStruct);	
}
//
void led_ctrl(uint16_t LED, u8 LED_Status)
{
	if(LED_Status == 0)	//LED_OFF
	{
		GPIO_SetBits(GPIOC, LED);
		GPIO_SetBits(GPIOD, GPIO_Pin_2);
		GPIO_ResetBits(GPIOD, GPIO_Pin_2);
	}
	else				//LED_ON
	{
		GPIO_ResetBits(GPIOC, LED);
		GPIO_SetBits(GPIOD, GPIO_Pin_2);
		GPIO_ResetBits(GPIOD, GPIO_Pin_2);
	}
}
//







