#include "sensor.h"
#include <stdio.h>
#include <stdlib.h>


#define DATA_PATH "test_data.txt"

/* Current implementation covers only test data processing (without real data from sensor). */

int8_t sensorInit(void)
{
    FILE *fp = fopen(DATA_PATH, "w");

    if(fp == NULL)
    {
        printf("Failed to open file [%s] \n", DATA_PATH);
        return -1;
    }
    
    fprintf(fp, "200\n");
    fclose(fp);

    return 0;
}

int32_t sensorReadData(void)
{
    FILE *fp = fopen(DATA_PATH, "r");
    int32_t luxData = 0;

    if(fp == NULL)
    {
        printf("Failed to open file [%s] \n", DATA_PATH);
        return -1;
    }

    if(fscanf(fp, "%d", &luxData) != 1)
    {
        printf("Failed to fetch test data from [%s] \n", DATA_PATH);
        return -1;
    }

    return luxData;

}
