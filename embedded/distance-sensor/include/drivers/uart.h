#pragma once
#include "hardware/uart.h"

#define UART_BAUD 115200
#define UART_CH uart1

/*
@brief initialize the UART module 
*/
void my_uart_init();

/*
@brief sends payload over UART_CH
*/
void uart_write();