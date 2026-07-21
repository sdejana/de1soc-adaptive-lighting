#ifndef SENSOR_H
#define SENSOR_H

#include <stdint.h>

/*
    Sensor initialisation function.
*/
int8_t sensorInit(void);

/*
    Real function used to read sensor data.
 */
double sensorReadData(void);

#endif