#include "hardware/i2c.h"
#include "i2c.h"

void rover_i2c_init()
{
    i2c_init(I2C_PORT, I2C_BAUD);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);
}

void i2c_read_esp32(uint8_t* data, uint8_t num_bytes){
    int num_bytes_read = 0;

    // First, read data from I2C buffer
        num_bytes_read = i2c_read_timeout_us(
            I2C_PORT,
            ESP32_I2C_ADDRESS,
            data,
            num_bytes,
            false,                  // nostop = false (If true, master retains control of >
            I2C_TIMEOUT_DELAY
        );

    // Second, print debug message
        if (num_bytes_read < 0){
            printf("i2c_read_remoteXY(): I2C error (%d)\n", num_bytes_read);
        }
        else if (num_bytes_read != num_bytes){
            printf("i2c_read_remoteXY(): expected %u bytes, received %d\n", num_bytes, num>
        }

    // Lastly, return to main program
        return;
}

void i2c_write_esp32(uint8_t* data, uint8_t num_bytes){

    // First, write data to I2C bus
        i2c_write_blocking(I2C_PORT, ESP32_I2C_ADDRESS, data, num_bytes, false);

    // Second, print debug message
        printf("> i2c_write_esp32(): wrote %u bytes to I2c bus\n", num_bytes);

    // Lastly, return to main program
        return;
}
