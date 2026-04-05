#ifndef I2C_H_
#define I2C_H_

#include "hardware/i2c.h"
#include "board_config.h"

#define I2C_BAUD 100 * 1000
#define I2C_PORT i2c0
#define RP2350_I2C_ADDR 0x40
#define ESP32_I2C_ADDR 0x20

/*
@brief initializes the I2C bus for communicating with other devices
*/
void rover_i2c_init();

/*
@brief read data from ESP32 which outputs data from RemoteXY app
@param data pointer to location for storing recieved data
@param num_bytes number of bytes to be read from ESP32
*/
void i2c_read_esp32(uint8_t* data, uint8_t num_bytes);

/*
@brief writes data to ESP32
@param data pointer to location of data to write
@param number of bytes to write
*/
void i2c_write_esp32(uint8_t* data, uint8_t num_bytes);


#endif