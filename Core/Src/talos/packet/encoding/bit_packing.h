#ifndef BIT_PACKING_H
#define BIT_PACKING_H

#include <cstdint>

class BitPacking
{
public:
    BitPacking();

    void AddBits(uint32_t value, uint8_t bitCount);

    const uint8_t* GetData() const;
    uint16_t GetSize() const;

private:
    static const uint16_t MAX_SIZE = 128;

    uint8_t data[MAX_SIZE];
    uint16_t bitPosition;
};

#endif