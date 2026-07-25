#include "MovementValidator.h"
#include <cmath>

bool MovementValidator::ValidateAndApply(PlayerState& state, const ClientInputPacket& input, float maxSpeed)
{
    // Calculate distance
    float dist = std::hypot(input.inputX - state.x, input.inputY - state.y);

    // Max allowed
    float maxDist = maxSpeed * input.deltaTime;

    if (dist <= maxDist)
    {
        // Accept movement
        state.x            = input.inputX;
        state.y            = input.inputY;
        state.lastSequence = input.sequenceNumber;
        return true;
    }

    // Reject movement
    return false;
}
