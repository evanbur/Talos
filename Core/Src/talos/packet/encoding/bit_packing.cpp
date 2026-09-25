#include "bit_packing.h"

BitPacking::BitPacking()
    : data{}, bitPosition(0)
{
}

void BitPacking::AddBits(uint32_t value, uint8_t bitCount)
{
    for (int i = bitCount - 1; i >= 0; i--)
    {
        uint8_t bit = (value >> i) & 1;

        uint16_t bytePosition = bitPosition / 8;
        uint8_t bitInByte = 7 - (bitPosition % 8);

        data[bytePosition] |= bit << bitInByte;

        bitPosition++;
    }
}

const uint8_t* BitPacking::GetData() const
{
    return data;
}

uint16_t BitPacking::GetSize() const
{
    return (bitPosition + 7) / 8;
}