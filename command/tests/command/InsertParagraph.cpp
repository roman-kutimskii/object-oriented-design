#include <gtest/gtest.h>

#include "../../src/command/InsertParagraph.h"
#include "../MockDocument.h"

TEST(InsertParagraphTest, ExecuteInsertsParagraphAtSpecifiedPosition)
{
    const auto mockDocument = std::make_shared<MockDocument>();
    const std::string text = "Test paragraph";
    constexpr std::optional<size_t> position = 0;

    EXPECT_CALL(*mockDocument, InsertParagraph(text, position)).Times(1);

    InsertParagraph command(mockDocument, text, position);
    command.Execute();
}

TEST(InsertParagraphTest, ExecuteInsertsParagraphAtEndWhenPositionNotSpecified)
{
    const auto mockDocument = std::make_shared<MockDocument>();
    const std::string text = "Test paragraph";
    constexpr std::optional<size_t> position = std::nullopt;

    EXPECT_CALL(*mockDocument, InsertParagraph(text, position)).Times(1);

    InsertParagraph command(mockDocument, text);
    command.Execute();
}

TEST(InsertParagraphTest, UnexecuteDeletesParagraphAtSpecifiedPosition)
{
    const auto mockDocument = std::make_shared<MockDocument>();
    const std::string text = "Test paragraph";
    constexpr std::optional<size_t> position = 0;

    EXPECT_CALL(*mockDocument, InsertParagraph(text, position)).Times(1);
    EXPECT_CALL(*mockDocument, DeleteItem(position.value())).Times(1);

    InsertParagraph command(mockDocument, text, position);
    command.Execute();
    command.Unexecute();
}

TEST(InsertParagraphTest, UnexecuteDeletesLastParagraphWhenPositionNotSpecified)
{
    const auto mockDocument = std::make_shared<MockDocument>();
    const std::string text = "Test paragraph";
    constexpr std::optional<size_t> position = std::nullopt;

    EXPECT_CALL(*mockDocument, InsertParagraph(text, position)).Times(1);
    EXPECT_CALL(*mockDocument, GetItemsCount()).WillOnce(testing::Return(1));
    EXPECT_CALL(*mockDocument, DeleteItem(0)).Times(1);

    InsertParagraph command(mockDocument, text);
    command.Execute();
    command.Unexecute();
}
