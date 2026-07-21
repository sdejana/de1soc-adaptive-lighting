#include "sensor.h"
#include <stdio.h>
#include <stdlib.h>


#define SENSOR_IIO_DIR_PATH "/sys/bus/iio/devices/iio:device0"
#define SENSOR_SCALE 0.25

/*
    Used to calibrate sensor.
*/
static void setParam (const char* paramName, const char* paramValue)
{
    char path[128];
    snprintf(path, sizeof(path), "%s/%s", SENSOR_IIO_DIR_PATH, paramName);

    FILE* fp = fopen(path, "w");
    if(fp == NULL)
    {
        printf("Failed to open file [%s] \n", path);
        return;
    }

    fputs(paramValue, fp);

    fclose(fp);
}

int8_t sensorInit(void)
{
    setParam("in_illuminance_scale", "0.25");
    setParam("in_illuminance_integration_time", "0.1");

    return 0;
}

double sensorReadData(void)
{
    char path[128];

    snprintf(path, sizeof(path), "%s/in_illuminance_raw", SENSOR_IIO_DIR_PATH);

    FILE *fp = fopen(path, "r");
    if(fp == NULL)
    {
        printf("Failed to open file [%s] \n", path);
        return -1;
    }

    double rawLuxData = 0.0;

    if (fscanf(fp, "%lf", &rawLuxData) != 1)
    {
        printf("Failed to read valid data from [%s] \n", path);
        fclose(fp);
        return -1.0;
    }

    fclose(fp);

    return rawLuxData * SENSOR_SCALE;
}
