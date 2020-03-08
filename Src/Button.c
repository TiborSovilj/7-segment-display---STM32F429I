#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "../Inc/stm32f4xx.h"
#include "../Inc/LED_7_Functions.h"

GPIO_TypeDef* gpioa = GPIOA;

void buttonInit(){
	CLEAR_BIT(gpioa->MODER, 0x00000003);	
}


uint8_t isButton(){
	int state = (int)((uint32_t*)gpioa->IDR) & (1 << 0);

	if (state == 1) 	return 1;
	else 			return 0;
}