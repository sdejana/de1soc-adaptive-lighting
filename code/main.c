#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <unistd.h>
#include "sensor.h"
#include "led.h"

#define MAIN_DELAY_INTERVAL 200000
#define MAIN_STABLE_READS_REQ 4

static uint8_t mainComputeTarget(double lux) 
{
    double minLux = 1.0;    // near-dark
    double maxLux = 500.0;  // bright room lighting
    if (lux < minLux) lux = minLux;
    if (lux > maxLux) lux = maxLux;

    double decades = log10(maxLux / minLux); // how many decades total
    double frac = log10(lux / minLux) / decades; // 0 (dark) .. 1 (bright)
    uint8_t count = (uint8_t)((1.0 - frac) * LED_NUM + 0.5);
    return count;
}


int main(void)
{
    if (sensorInit() != 0)
    {
        printf("Sensor init failed. \n");
        return 1;
    }

    int8_t currentCount = -1;
    int8_t pendingCount = -1;
    uint8_t stableReads = 0;

    while(1)
    {
        double luxData = sensorReadData();
        uint8_t target = mainComputeTarget(luxData);

        if (target == pendingCount) 
        {
            stableReads++;
        }
        else 
        { 
            pendingCount = target; 
            stableReads = 1; 
        }

        if (stableReads >= MAIN_STABLE_READS_REQ && target != currentCount) 
        {
            ledUpdateFromLux(target);
            printf("lux=%.2f -> %d LEDs lit\n", luxData, target);
            currentCount = target;
        }

        usleep(MAIN_DELAY_INTERVAL);
    }

    return 0;
}
