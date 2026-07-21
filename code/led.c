#include "led.h"
#include <stdio.h>

void ledSet(uint8_t ledIndex, uint8_t ledOn)
{
    char path[128];

    snprintf(path, sizeof(path), "/sys/class/leds/fpga_led%d/brightness", ledIndex);

    FILE* fp = fopen(path, "w");
    if(fp == NULL)
    {
        printf("Failed to open file [%s] \n", path);
        return;
    }

    if(ledOn)
    {
        fprintf(fp, "%d\n", 1);
    }
    else
    {
        fprintf(fp, "%d\n", 0);
    }

    fclose(fp);
}

void ledUpdateFromLux(uint8_t ledCount)
{
    if (ledCount < LED_NUM)
    {
        for (uint8_t i = 0; i < LED_NUM; i++)
        {
            ledSet(i, i < ledCount);
        }
    }
}