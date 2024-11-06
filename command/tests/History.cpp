#include <gtest/gtest.h>

#include "../src/History.h"
#include "MockCommand.h"
#include "MockUndoableCommand.h"

TEST(HistoryTest, AddCommandClearsRedoStack)
{
    History history;
    auto command = std::make_unique<testing::NiceMock<MockUndoableCommand>>();
    history.AddCommand(std::move(command));
    EXPECT_FALSE(history.CanRedo());
}

TEST(HistoryTest, UndoMovesCommandToRedoStack)
{
    History history;
    auto command = std::make_unique<MockUndoableCommand>();
    MockUndoableCommand *commandPtr = command.get();

    EXPECT_CALL(*commandPtr, Unexecute()).Times(testing::Exactly(1));

    history.AddCommand(std::move(command));
    history.Undo();

    EXPECT_FALSE(history.CanUndo());
    EXPECT_TRUE(history.CanRedo());
}

TEST(HistoryTest, RedoMovesCommandToUndoStack)
{
    History history;
    auto command = std::make_unique<MockUndoableCommand>();
    MockUndoableCommand *commandPtr = command.get();

    EXPECT_CALL(*commandPtr, Execute()).Times(testing::Exactly(1));

    history.AddCommand(std::move(command));
    history.Undo();
    history.Redo();

    EXPECT_TRUE(history.CanUndo());
    EXPECT_FALSE(history.CanRedo());
}

TEST(HistoryTest, UndoThrowsIfNoCommands)
{
    History history;
    EXPECT_THROW(history.Undo(), std::out_of_range);
}

TEST(HistoryTest, RedoThrowsIfNoCommands)
{
    History history;
    EXPECT_THROW(history.Redo(), std::out_of_range);
}
