#include <gtest/gtest.h>
#include "../src/gameplay_logic/MovementValidator.h"
#include "../src/network_layer/Packets.h"

TEST(MovementValidatorTest, ValidMovement)
{
    // Setup state
    PlayerState state{0.0f, 0.0f, 0};
    ClientInputPacket input{1, 3.0f, 4.0f, 1.0f};

    // Validate movement
    bool result = MovementValidator::ValidateAndApply(state, input, 5.0f);

    // Assert valid
    EXPECT_TRUE(result);
    EXPECT_FLOAT_EQ(state.x, 3.0f);
    EXPECT_FLOAT_EQ(state.y, 4.0f);
    EXPECT_EQ(state.lastSequence, 1);
}

TEST(MovementValidatorTest, SpeedhackBlocked)
{
    // Setup state
    PlayerState state{0.0f, 0.0f, 0};
    ClientInputPacket input{2, 10.0f, 10.0f, 1.0f};

    // Validate movement
    bool result = MovementValidator::ValidateAndApply(state, input, 5.0f);

    // Assert blocked
    EXPECT_FALSE(result);
    EXPECT_FLOAT_EQ(state.x, 0.0f);
    EXPECT_FLOAT_EQ(state.y, 0.0f);
    EXPECT_EQ(state.lastSequence, 0);
}
