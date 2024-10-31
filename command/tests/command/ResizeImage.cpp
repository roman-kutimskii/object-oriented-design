#include <gtest/gtest.h>

#include "../../src/command/ResizeImage.h"
#include "../MockDocument.h"
#include "../MockImage.h"
#include "../MockParagraph.h"

TEST(ResizeImageTest, ExecuteResizesImageSuccessfully)
{
    const auto mockDocument = std::make_shared<MockDocument>();
    const auto mockImage = std::make_shared<MockImage>();
    constexpr size_t position = 0;
    constexpr int newWidth = 1024;
    constexpr int newHeight = 768;
    constexpr int oldWidth = 800;
    constexpr int oldHeight = 600;

    EXPECT_CALL(*mockDocument, GetItem(position)).WillOnce(testing::Return(DocumentItem(mockImage)));

    EXPECT_CALL(*mockImage, GetWidth()).WillOnce(testing::Return(oldWidth));
    EXPECT_CALL(*mockImage, GetHeight()).WillOnce(testing::Return(oldHeight));

    EXPECT_CALL(*mockImage, Resize(newWidth, newHeight)).Times(1);

    ResizeImage command(mockDocument, newWidth, newHeight, position);
    command.Execute();
}

TEST(ResizeImageTest, ExecuteThrowsWhenImageNotFound)
{
    const auto mockDocument = std::make_shared<MockDocument>();
    const auto mockParagraph = std::make_shared<MockParagraph>();
    constexpr size_t position = 0;

    EXPECT_CALL(*mockDocument, GetItem(position)).WillOnce(testing::Return(DocumentItem(mockParagraph)));

    ResizeImage command(mockDocument, 1024, 768, position);

    EXPECT_THROW(command.Execute(), std::invalid_argument);
}

TEST(ResizeImageTest, UnexecuteRestoresPreviousSize)
{
    const auto mockDocument = std::make_shared<MockDocument>();
    const auto mockImage = std::make_shared<MockImage>();
    constexpr size_t position = 0;
    constexpr int newWidth = 1024;
    constexpr int newHeight = 768;
    constexpr int oldWidth = 800;
    constexpr int oldHeight = 600;

    EXPECT_CALL(*mockDocument, GetItem(position)).WillRepeatedly(testing::Return(DocumentItem(mockImage)));

    EXPECT_CALL(*mockImage, GetWidth()).WillOnce(testing::Return(oldWidth));
    EXPECT_CALL(*mockImage, GetHeight()).WillOnce(testing::Return(oldHeight));

    EXPECT_CALL(*mockImage, Resize(newWidth, newHeight)).Times(1);

    EXPECT_CALL(*mockImage, Resize(oldWidth, oldHeight)).Times(1);

    ResizeImage command(mockDocument, newWidth, newHeight, position);
    command.Execute();
    command.Unexecute();
}
