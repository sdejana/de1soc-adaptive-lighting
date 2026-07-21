#ifndef LED_H
#define LED_H

#include <stdint.h>

#define LED_NUM 10


/*
    Updates led state based on led index and desired led state.
*/
void ledSet(uint8_t ledIndex, uint8_t ledOn);

/*
    Updates multiple leds state based on light level.
*/
void ledUpdateFromLux(uint8_t ledCount);

#endif 