#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "../Inc/stm32f4xx.h"
#include "../Inc/LED_7_Functions.h"

GPIO_TypeDef* gpiof = GPIOF;
uint8_t SEGMENT_ARRAY[16] = {0x7E,0x30,0x6D,0x79,0x33,0x5B,0x5F,0x70,0x7F,0x7B,0x77,0x1F,0x4E,0x3D,0x4F,0x47};
//uint8_t SEGMENT_ARRAY[16] = {0x81, 0xcf, 0x92, 0x86, 0xcc, 0xa4, 0xa0, 0x8f, 0x80, 0x84, 0x88, 0xe0, 0xb1, 0xc2, 0xb0, 0xb8};


void LEDInit(){
	SET_BIT(gpiof->MODER, 0x00001555);
}

void setSegment(uint8_t segmentHex){
    SET_BIT(gpiof->ODR, 0x7F);
    CLEAR_BIT(gpiof->ODR, segmentHex);
}


void changeSegmentState(count){
        SET_BIT(gpiof->ODR, 0x7F);
        CLEAR_BIT(gpiof->ODR, SEGMENT_ARRAY[count]);
}
