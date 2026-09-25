#include "talos.h"

#include "main.h"
#include "util/uart.h"
#include "usart.h"

#include <cstdio>

static UART debug(&huart3);
static UART radio(&huart6);

static void SuccessAnimation();
static void ErrorAnimation();

static int packet_num = 0;

void Telemetry_Init()
{
    SuccessAnimation();

    radio.Write("Telemetry initialized");
    radio.NewLine();

    debug.Write("Telemetry initialized");
    debug.NewLine();
}

void Telemetry_Update()
{
    packet_num++;

    char buffer[32];

    snprintf(
        buffer,
        sizeof(buffer),
        "Hello world! #%d",
        packet_num
    );

    radio.Write("Hello world!");
    radio.NewLine();


    snprintf(
        buffer,
        sizeof(buffer),
        "Sent packet! #%d",
        packet_num
    );

    // Writes to the serial port and can use this for debugging
    debug.Write(buffer);
    debug.NewLine();
}

static void SuccessAnimation()
{
    // Turn all off
    HAL_GPIO_WritePin(
        GPIOB,
        LD1_Pin | LD2_Pin | LD3_Pin,
        GPIO_PIN_RESET
    );

    // LD1
    HAL_GPIO_WritePin(GPIOB, LD1_Pin, GPIO_PIN_SET);
    HAL_Delay(300);
    HAL_GPIO_WritePin(GPIOB, LD1_Pin, GPIO_PIN_RESET);

    // LD2
    HAL_GPIO_WritePin(GPIOB, LD2_Pin, GPIO_PIN_SET);
    HAL_Delay(300);
    HAL_GPIO_WritePin(GPIOB, LD2_Pin, GPIO_PIN_RESET);

    // LD3
    HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_SET);
    HAL_Delay(300);
    HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_RESET);

    for (int i = 0; i < 3; i++)
    {
        HAL_GPIO_WritePin(GPIOB, LD1_Pin, GPIO_PIN_SET);
        HAL_Delay(200);

        HAL_GPIO_WritePin(GPIOB, LD1_Pin, GPIO_PIN_RESET);
        HAL_Delay(200);
    }
}

static void ErrorAnimation()
{
    // Turn all off
    HAL_GPIO_WritePin(
        GPIOB,
        LD1_Pin | LD2_Pin | LD3_Pin,
        GPIO_PIN_RESET
    );

    // Flash all
    for (int i = 0; i < 10; i++)
    {
        HAL_GPIO_WritePin(
            GPIOB,
            LD1_Pin | LD2_Pin | LD3_Pin,
            GPIO_PIN_SET
        );

        HAL_Delay(50);

        HAL_GPIO_WritePin(
            GPIOB,
            LD1_Pin | LD2_Pin | LD3_Pin,
            GPIO_PIN_RESET
        );

        HAL_Delay(50);
    }

    // Blink error
    while (1)
    {
        HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_SET);
        HAL_Delay(200);

        HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_RESET);
        HAL_Delay(200);
    }
}