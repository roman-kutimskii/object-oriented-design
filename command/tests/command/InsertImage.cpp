#include <gtest/gtest.h>

#include "../../src/command/InsertImage.h"
#include "../MockDocument.h"

TEST(InsertImageTest, ExecuteInsertsImageAtSpecifiedPosition)
{
    const auto mockDocument = std::make_shared<MockDocument>();
    const std::string path = "path/to/image.png";
    constexpr int width = 800;
    constexpr int height = 600;
    constexpr std::optional<size_t> position = 0;

    EXPECT_CALL(*mockDocument, InsertImage(path, width, height, position)).Times(1);

    InsertImage command(mockDocument, path, width, height, position);
    command.Execute();
}

TEST(InsertImageTest, ExecuteInsertsImageAtEndWhenPositionNotSpecified)
{
    const auto mockDocument = std::make_shared<MockDocument>();
    const std::string path = "path/to/image.png";
    constexpr int width = 800;
    constexpr int height = 600;
    constexpr std::optional<size_t> position = std::nullopt;

    EXPECT_CALL(*mockDocument, InsertImage(path, width, height, position)).Times(1);

    InsertImage command(mockDocument, path, width, height);
    command.Execute();
}

TEST(InsertImageTest, UnexecuteDeletesImageAtSpecifiedPosition)
{
    const auto mockDocument = std::make_shared<MockDocument>();
    const std::string path = "path/to/image.png";
    constexpr int width = 800;
    constexpr int height = 600;
    constexpr std::optional<size_t> position = 0;

    EXPECT_CALL(*mockDocument, InsertImage(path, width, height, position)).Times(1);
    EXPECT_CALL(*mockDocument, DeleteItem(position.value())).Times(1);

    InsertImage command(mockDocument, path, width, height, position);
    command.Execute();
    command.Unexecute();
}

TEST(InsertImageTest, UnexecuteDeletesLastImageWhenPositionNotSpecified)
{
    const auto mockDocument = std::make_shared<MockDocument>();
    const std::string path = "path/to/image.png";
    constexpr int width = 800;
    constexpr int height = 600;
    constexpr std::optional<size_t> position = std::nullopt;

    EXPECT_CALL(*mockDocument, InsertImage(path, width, height, position)).Times(1);
    EXPECT_CALL(*mockDocument, GetItemsCount()).WillOnce(testing::Return(1));
    EXPECT_CALL(*mockDocument, DeleteItem(0)).Times(1);

    InsertImage command(mockDocument, path, width, height);
    command.Execute();
    command.Unexecute();
}
