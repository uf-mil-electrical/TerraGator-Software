#pragma once
#include <inttypes.h>

#define DIST_BUF_SIZE 5 
#define SONAR_NUM 4
#define SONAR_TIMEOUT_US 26100 

class Sonar {
    public:

        /*
        @brief Sonar class constructor 
        @param trig TRIGGER pin of sonar module
        @param echo ECHO pin of sonar module
        */
        Sonar(uint32_t trig, uint32_t echo);

        /*
        @brief initializes the sonar GPIO 
        */
        void sonar_init();

        /*
        @brief takes distance measurement from the sonar
        @return the distance measured by the sonar. If <0, reading is out of range
        */
        float read_distance_cm();

        /*
        @brief takes multiple distance measurements and finds median to remove the occassional measurement spike/noise 
        @return median measurement from a read buffer of size SONAR_BUF_SIZE
        */
        float get_median_distance_cm();

    private:
        uint32_t trig_pin;
        uint32_t echo_pin;    
}; 

