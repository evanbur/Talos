#include "packet.h"

Packet::Packet()
{
    size = 0;
}

void Packet::AddByte(uint8_t value)
{
    if (size < MAX_SIZE)
    {
        data[size] = value;
        size++;
    }
}

void Packet::AddUInt16(uint16_t value)
{
    AddByte(value >> 8);
    AddByte(value);
}

void Packet::AddInt16(int16_t value)
{
    AddUInt16((uint16_t)value);
}

void Packet::AddUInt32(uint32_t value)
{
    AddByte(value >> 24);
    AddByte(value >> 16);
    AddByte(value >> 8);
    AddByte(value);
}

void Packet::AddInt32(int32_t value)
{
    AddUInt32((uint32_t)value);
}

uint8_t* Packet::GetData()
{
    return data;
}

uint16_t Packet::GetSize()
{
    return size;
}

void Packet::Clear()
{
    size = 0;
}