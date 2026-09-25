#include "packet_builder.h"
/*
 * Once we have the actual list of sensors we can add more fields than just RPM.
 */

PacketBuilder::PacketBuilder()
{
    rpm = 0;
    speed = 0;
    beltTemp = 0;
}

void PacketBuilder::SetRPM(uint16_t rpm)
{
    this->rpm = rpm;
}

Packet PacketBuilder::BuildTelemetryPacket()
{
    Packet packet;

    packet.AddUInt16(rpm);
    return packet;
}