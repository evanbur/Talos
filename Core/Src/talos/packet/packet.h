#ifndef PACKET_H
#define PACKET_H

#include <cstdint>

class Packet
{
public:
    Packet();

    void AddByte(uint8_t value);
    void AddUInt16(uint16_t value);
    void AddInt16(int16_t value);
    void AddUInt32(uint32_t value);
    void AddInt32(int32_t value);

    uint8_t* GetData();
    uint16_t GetSize();

    void Clear();

private:
    static const uint16_t MAX_SIZE = 128;

    uint8_t data[MAX_SIZE];
    uint16_t size;
};

#endif