#ifndef SENSOR_H
#define SENSOR_H

#include <stdint.h>

/*
    Sensor initialisation function.
*/
int8_t sensorInit(void);

/*
    Dummy func used for simulating sensor data.
 */
int32_t sensorReadData(void);

#endif