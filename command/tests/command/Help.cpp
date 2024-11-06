#include <gtest/gtest.h>

#include "../../src/command/Help.h"
#include "../MockMenu.h"

TEST(HelpCommandTest, ExecuteCallsMenuShowInstructions)
{
    const auto mockMenu = std::make_unique<testing::NiceMock<MockMenu>>();
    const auto command = std::make_unique<Command::Help>(mockMenu.get());

    EXPECT_CALL(*mockMenu, ShowInstructions()).Times(1);

    command->Execute();
}
