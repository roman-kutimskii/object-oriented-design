#include "../../src/command/MarkDeleted.h"


#include <gtest/gtest.h>

#include "../MockDocument.h"
#include "../MockImage.h"
#include "../MockParagraph.h"

TEST(MarkDeletedTest, ExecuteMarksImageAsDeleted)
{
    const auto mockDocument = std::make_shared<MockDocument>();
    const auto mockImage = std::make_shared<MockImage>();
    constexpr size_t position = 0;

    EXPECT_CALL(*mockDocument, GetItem(position)).WillOnce(testing::Return(DocumentItem(mockImage)));

    EXPECT_CALL(*mockImage, SetDeleted(true)).Times(1);

    MarkDeleted command(mockDocument, position);
    command.Execute();
}

TEST(MarkDeletedTest, ExecuteThrowsWhenImageNotFound)
{
    const auto mockDocument = std::make_shared<MockDocument>();
    const auto mockParagraph = std::make_shared<MockParagraph>();
    constexpr size_t position = 0;

    EXPECT_CALL(*mockDocument, GetItem(position)).WillOnce(testing::Return(DocumentItem(mockParagraph)));

    MarkDeleted command(mockDocument, position);

    EXPECT_THROW(command.Execute(), std::invalid_argument);
}

TEST(MarkDeletedTest, UnexecuteRestoresImageFromDeleted)
{
    const auto mockDocument = std::make_shared<MockDocument>();
    const auto mockImage = std::make_shared<MockImage>();
    constexpr size_t position = 0;

    EXPECT_CALL(*mockDocument, GetItem(position)).WillOnce(testing::Return(DocumentItem(mockImage)));

    EXPECT_CALL(*mockImage, SetDeleted(true)).Times(1);
    EXPECT_CALL(*mockImage, SetDeleted(false)).Times(1);

    MarkDeleted command(mockDocument, position);
    command.Execute();
    command.Unexecute();
}
