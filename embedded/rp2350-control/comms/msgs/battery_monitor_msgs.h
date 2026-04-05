#ifndef BATTERY_MONITOR_MSGS_H
#define BATTERY_MONITOR_MSGS_H

#include <stdint.h>

typedef struct battery_status {
    uint8_t status;
    int16_t voltage; 
    int16_t current; 
} battery_status_t;

#endif 