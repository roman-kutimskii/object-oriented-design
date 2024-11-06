#include <gtest/gtest.h>

#include "../../src/command/Redo.h"
#include "../MockHistory.h"

TEST(RedoCommandTest, ExecuteCallsHistoryMethods)
{
    const auto mockHistory = std::make_unique<testing::NiceMock<MockHistory>>();
    const auto command = std::make_unique<Command::Redo>(mockHistory.get());

    EXPECT_CALL(*mockHistory, CanRedo()).WillOnce(testing::Return(true));
    EXPECT_CALL(*mockHistory, Redo()).Times(1);

    command->Execute();
}

TEST(RedoCommandTest, ExecuteDoesntCallsHistoryMethods)
{
    const auto mockHistory = std::make_unique<testing::NiceMock<MockHistory>>();
    const auto command = std::make_unique<Command::Redo>(mockHistory.get());

    EXPECT_CALL(*mockHistory, CanRedo()).WillOnce(testing::Return(false));
    EXPECT_CALL(*mockHistory, Redo()).Times(0);

    command->Execute();
}
