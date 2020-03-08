#ifndef LED_7_SEGMENT
#define LED_7_SEGMENT

#include "stdint.h"

void buttonInit();
uint8_t isButton();
void LEDInit();
void changeSegmentState(int);
void setSegment(uint8_t);

#endif