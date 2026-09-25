#include "uart.h"

#include <cstring>

UART::UART(UART_HandleTypeDef* uart)
    : uart_(uart)
{
}

bool UART::Write(const void* data, size_t length)
{
    return HAL_UART_Transmit(
               uart_,
               (uint8_t*)data,
               length,
               HAL_MAX_DELAY
           ) == HAL_OK;
}

bool UART::Write(const char* str)
{
    return Write(str, strlen(str));
}

bool UART::Write(char c)
{
    return Write(&c, 1);
}

bool UART::Write(uint8_t value)
{
    return Write(&value, 1);
}

void UART::NewLine()
{
    Write("\r\n");
}