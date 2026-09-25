#ifndef PACKET_BUILDER_H
#define PACKET_BUILDER_H

#include <cstdint>
#include "packet.h"

class PacketBuilder
{
public:
    PacketBuilder();

    void SetRPM(uint16_t rpm);
    void SetSpeed(uint16_t speed);
    void SetBeltTemp(uint16_t beltTemp);

    Packet BuildTelemetryPacket();

private:
    uint16_t rpm;
    uint16_t speed;
    uint16_t beltTemp;
};

#endif