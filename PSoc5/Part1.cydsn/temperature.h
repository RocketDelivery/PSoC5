#ifndef PSOC5_PART1_TEMPERATURE_H_
#define PSOC5_PART1_TEMPERATURE_H_

#include <stdint.h>
    
void temperatureInit();
uint16_t temperatureReadBlocking();

#endif
