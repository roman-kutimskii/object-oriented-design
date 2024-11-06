#include <gtest/gtest.h>

#include "../../src/command/Undo.h"
#include "../MockHistory.h"

TEST(UndoCommandTest, ExecuteCallsHistoryMethods)
{
    const auto mockHistory = std::make_unique<testing::NiceMock<MockHistory>>();
    const auto command = std::make_unique<Command::Undo>(mockHistory.get());

    EXPECT_CALL(*mockHistory, CanUndo()).WillOnce(testing::Return(true));
    EXPECT_CALL(*mockHistory, Undo()).Times(1);

    command->Execute();
}

TEST(UndoCommandTest, ExecuteDoesntCallsHistoryMethods)
{
    const auto mockHistory = std::make_unique<testing::NiceMock<MockHistory>>();
    const auto command = std::make_unique<Command::Undo>(mockHistory.get());

    EXPECT_CALL(*mockHistory, CanUndo()).WillOnce(testing::Return(false));
    EXPECT_CALL(*mockHistory, Undo()).Times(0);

    command->Execute();
}
