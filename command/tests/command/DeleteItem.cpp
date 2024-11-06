#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../../src/command/DeleteItem.h"
#include "../MockDocument.h"
#include "../MockImage.h"
#include "../MockParagraph.h"

TEST(DeleteItemTest, ExecuteCallsDeleteItemIfParagraph)
{
    const auto mockDocument = std::make_shared<MockDocument>();
    const auto mockParagraph = new MockParagraph();
    constexpr size_t position = 0;

    EXPECT_CALL(*mockDocument, GetItem(position)).WillOnce(::testing::Return(mockParagraph));
    EXPECT_CALL(*mockDocument, DeleteItem(position));

    DeleteItem command(mockDocument, position);
    command.Execute();
}

TEST(DeleteItemTest, UnexecuteCallsInsertImage)
{
    const auto mockDocument = std::make_shared<MockDocument>();
    constexpr std::optional<size_t> position = 0;

    EXPECT_CALL(*mockDocument, DeleteItem(position.value()))
        .WillOnce(::testing::Return(::testing::ByMove(std::make_unique<ConstDocumentItem>(std::make_shared<MockImage>())
        )));
    EXPECT_CALL(*mockDocument, InsertImage("", 0, 0, position)).Times(1);

    DeleteItem command(mockDocument, position.value());
    command.Execute();
    command.Unexecute();
}

TEST(DeleteItemTest, UnexecuteCallsInsertParagraph)
{
    const auto mockDocument = std::make_shared<MockDocument>();
    constexpr std::optional<size_t> position = 0;

    EXPECT_CALL(*mockDocument, DeleteItem(position.value()))
        .WillOnce(
            ::testing::Return(::testing::ByMove(std::make_unique<ConstDocumentItem>(std::make_shared<MockParagraph>())))
        );
    EXPECT_CALL(*mockDocument, InsertParagraph("", position)).Times(1);

    DeleteItem command(mockDocument, position.value());
    command.Execute();
    command.Unexecute();
}
