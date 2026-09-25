#ifndef BAJA_TALOS_FIXED_POINT_ENCODING_H
#define BAJA_TALOS_FIXED_POINT_ENCODING_H
#include <cstdint>


class FixedPoint {
    public:
        static int32_t Encode(float value, uint8_t precision);
};


#endif //BAJA_TALOS_FIXED_POINT_ENCODING_H
