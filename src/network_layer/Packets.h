#pragma once
#include <cstdint>

// Packed struct
#pragma pack(push, 1)
struct ClientInputPacket
{
    uint32_t sequenceNumber; // Sequence ID
    float inputX;            // X movement
    float inputY;            // Y movement
    float deltaTime;         // Frame delta
};
#pragma pack(pop)
