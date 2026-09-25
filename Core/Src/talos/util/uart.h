#pragma once

#include "usart.h"

#include <cstddef>
#include <cstdint>

#include "stm32f4xx_hal_uart.h"

class UART
{
public:
    explicit UART(UART_HandleTypeDef* uart);

    bool Write(const void* data, size_t length);

    bool Write(const char* str);

    bool Write(char c);

    bool Write(uint8_t value);

    void NewLine();

private:
    UART_HandleTypeDef* uart_;
};
