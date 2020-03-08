#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "../Inc/stm32f4xx.h"
#include "../Inc/LED_7_Functions.h"

void rccInit();
int count = 0;


int main(){
	rccInit();
        LEDInit();
        buttonInit();
        
        setSegment(0x36);

       	while(1){
		if (isButton() == 1){		
			changeSegmentState(count % 16);
                        count++;
			while(isButton()){
				if (!isButton()) break;
			}
		}
	}
	return 0;
}


void rccInit(){
      RCC_TypeDef* rcc = RCC;
      SET_BIT(rcc->AHB1ENR, RCC_AHB1ENR_GPIOFEN);
      SET_BIT(rcc->AHB1ENR, RCC_AHB1ENR_GPIOAEN);
}
