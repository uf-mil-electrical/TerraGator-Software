#include "drivers/sonar.h"
#include "hardware/gpio.h"
#include "utils/median.h"
#include "pico/stdlib.h"
#include "board_config.h"


Sonar::Sonar(uint32_t trig, uint32_t echo)
    : trig_pin(trig), echo_pin(echo) {sonar_init();}

void Sonar::sonar_init()
{
    gpio_init(trig_pin);
    gpio_init(echo_pin);
    
    gpio_set_dir(trig_pin, GPIO_OUT);
    gpio_put(trig_pin, 0);
    gpio_set_dir(echo_pin, GPIO_IN);
}

// Peter Feng's sonar read_distance function 
float Sonar::read_distance_cm()
{
    gpio_put(trig_pin, 1);
    sleep_us(10);
    gpio_put(trig_pin, 0);

    uint32_t wait_start = time_us_32();
    while (gpio_get(echo_pin) == 0) {
        if (time_us_32() - wait_start > SONAR_TIMEOUT_US) return -1.0f;
    }

    uint32_t start_time = time_us_32();
    while (gpio_get(echo_pin) == 1) {
        if (time_us_32() - start_time > SONAR_TIMEOUT_US) return -1.0f;
    }
    uint32_t end_time = time_us_32();

    uint32_t duration = end_time - start_time;
    return (float)duration * 0.0343f / 2.0f;
}

float Sonar::get_median_distance_cm()
{
    // max time it takes to get a reading (assumming all block for 26100 seconds)
    // is 26100 us * 5 = 26.1ms * 5 = 0.1305 seconds
    // limits output rate significantly if all readings are blocking
    float dist_buf[DIST_BUF_SIZE];
    for(int i = 0; i < DIST_BUF_SIZE; i++)
    {
        dist_buf[i] = read_distance_cm();
    }

    return median(dist_buf, DIST_BUF_SIZE);

}