#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "drivers/sonar.h"
#include "drivers/uart.h"
#include "utils/median.h"
#include "board_config.h"

#define UPDATE_LOOP_PERIOD_US 250000

int main()
{
    stdio_init_all();
    
    Sonar sonars[SONAR_NUM] =
    {
      Sonar(USS1_TRIG, USS1_ECHO),
      Sonar(USS2_TRIG, USS2_ECHO),
      Sonar(USS3_TRIG, USS3_ECHO),
      Sonar(USS4_TRIG, USS4_ECHO)
    };

    float sonar_readings[SONAR_NUM];

    while (true) 
    {
        uint32_t update_loop_start = time_us_32();
        for(int i = 0; i < SONAR_NUM; i++)
        {
            sonar_readings[i] = sonars[i].get_median_distance_cm();
            printf("sonar %d reading [cm]: %f", i, sonar_readings[i]);
        }

        if((time_us_32() - update_loop_start) > UPDATE_LOOP_PERIOD_US)
        {
            //uart_send(sonar_readings);
        }
    }   
}
