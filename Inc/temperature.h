/** 
  * MIT GOES HERE
  */
#ifndef temperature_H_
#define temperature_H_

#include <stdint.h>

float read_motherboard_sensor(uint8_t sensor_id);
float read_thermocouple_sensor(uint8_t sensor_id);

#endif
