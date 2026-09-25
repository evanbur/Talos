#include "fixed_point.h"
#include <cmath>

int32_t FixedPoint::Encode(float value, uint8_t decimalPlaces)
{
    int32_t multiplier = 1;

    for (uint8_t i = 0; i < decimalPlaces; i++)
    {
        multiplier *= 10;
    }

    float scaledValue = value * multiplier;

    return static_cast<int32_t>(std::round(scaledValue));
}