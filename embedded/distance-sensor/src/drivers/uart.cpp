#include "drivers/uart.h"
#include "hardware/gpio.h"
#include "board_config.h"

void my_uart_init()
{
    uart_init(UART_CH, UART_BAUD);
    gpio_set_function(UART1_TX, GPIO_FUNC_UART);
    gpio_set_function(UART1_RX, GPIO_FUNC_UART);
}

void uart_write()
{

}