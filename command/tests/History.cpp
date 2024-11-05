#include <gtest/gtest.h>

#include "../src/History.h"
#include "command/MockCommand.h"

TEST(History, AddCommandNotExecutesCommand)
{
    History history;
    auto command = std::make_unique<MockCommand>();

    EXPECT_CALL(*command, Execute()).Times(0);

    history.AddCommand(std::move(command));
}

TEST(History, UndoExecutesUnexecuteOnLastCommand)
{
    History history;
    auto command1 = std::make_unique<MockCommand>();
    auto command2 = std::make_unique<MockCommand>();

    {
        testing::InSequence seq;
        EXPECT_CALL(*command1, Execute());
        EXPECT_CALL(*command2, Execute());
        EXPECT_CALL(*command2, Unexecute());
    }

    history.AddCommand(std::move(command1));
    history.AddCommand(std::move(command2));
    history.Undo();
}

TEST(History, RedoExecutesExecuteOnNextCommand)
{
    History history;
    auto command1 = std::make_unique<MockCommand>();
    auto command2 = std::make_unique<MockCommand>();

    {
        testing::InSequence seq;
        EXPECT_CALL(*command1, Execute());
        EXPECT_CALL(*command2, Execute());
        EXPECT_CALL(*command2, Unexecute());
        EXPECT_CALL(*command2, Execute());
    }

    history.AddCommand(std::move(command1));
    history.AddCommand(std::move(command2));
    history.Undo();
    history.Redo();
}

TEST(History, CanUndoReturnsTrueAfterCommandAdded)
{
    History history;
    auto command = std::make_unique<MockCommand>();

    history.AddCommand(std::move(command));

    EXPECT_TRUE(history.CanUndo());
}

TEST(History, CanUndoReturnsFalseWhenNoCommands)
{
    const History history;

    EXPECT_FALSE(history.CanUndo());
}

TEST(History, CanRedoReturnsFalseWhenNoCommands)
{
    const History history;

    EXPECT_FALSE(history.CanRedo());
}

TEST(History, CanRedoReturnsFalseAfterCommandAdded)
{
    History history;
    auto command = std::make_unique<MockCommand>();

    history.AddCommand(std::move(command));

    EXPECT_FALSE(history.CanRedo());
}

TEST(History, CanRedoReturnsTrueAfterUndo)
{
    History history;
    auto command = std::make_unique<MockCommand>();

    history.AddCommand(std::move(command));
    history.Undo();

    EXPECT_TRUE(history.CanRedo());
}

TEST(History, ThrowsExceptionWhenUndoNotPossible)
{
    History history;

    EXPECT_THROW(history.Undo(), std::out_of_range);
}

TEST(History, ThrowsExceptionWhenRedoNotPossible)
{
    History history;

    EXPECT_THROW(history.Redo(), std::out_of_range);
}

TEST(History, ExceedingMaxSizeRemovesOldestCommand)
{
    History history;
    std::vector<std::unique_ptr<MockCommand>> commands;
    for (int i = 0; i < 11; ++i)
    {
        auto cmd = std::make_unique<MockCommand>();
        EXPECT_CALL(*cmd, Execute()).Times(1);
        commands.push_back(std::move(cmd));
    }

    for (int i = 0; i < 10; ++i)
    {
        history.AddCommand(std::move(commands[i]));
    }

    history.AddCommand(std::move(commands[10]));

    for (int i = 0; i < 10; ++i)
    {
        ASSERT_TRUE(history.CanUndo());
        history.Undo();
    }

    EXPECT_FALSE(history.CanUndo());
}
