#pragma once
#include "../network_layer/Packets.h"

// Player state
struct PlayerState
{
    float    x{0.0f};
    float    y{0.0f};
    uint32_t lastSequence{0};
};

// Validator
class MovementValidator
{
public:
    static bool ValidateAndApply(PlayerState& state, const ClientInputPacket& input, float maxSpeed);
};
