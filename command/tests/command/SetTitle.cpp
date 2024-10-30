#include <gtest/gtest.h>

#include "../../src/command/SetTitle.h"
#include "../MockDocument.h"

TEST(SetTitleTest, ExecuteSetsTitleToNewValue)
{
    const auto mockDocument = std::make_shared<MockDocument>();
    const std::string newTitle = "New Title";
    const std::string oldTitle = "Old Title";

    EXPECT_CALL(*mockDocument, GetTitle()).WillOnce(testing::Return(oldTitle));
    EXPECT_CALL(*mockDocument, SetTitle(newTitle)).Times(1);

    SetTitle command(mockDocument, newTitle);
    command.Execute();
}

TEST(SetTitleTest, UnexecuteRestoresPreviousTitle)
{
    const auto mockDocument = std::make_shared<MockDocument>();
    const std::string newTitle = "New Title";
    const std::string oldTitle = "Old Title";

    EXPECT_CALL(*mockDocument, GetTitle()).WillOnce(testing::Return(oldTitle));

    EXPECT_CALL(*mockDocument, SetTitle(newTitle)).Times(1);
    EXPECT_CALL(*mockDocument, SetTitle(oldTitle)).Times(1);

    SetTitle command(mockDocument, newTitle);
    command.Execute();
    command.Unexecute();
}
