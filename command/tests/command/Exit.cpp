#include <gtest/gtest.h>

#include "../../src/command/Exit.h"
#include "../MockMenu.h"

TEST(ExitCommandTest, ExecuteCallsMenuExit)
{
    const auto mockMenu = std::make_unique<testing::NiceMock<MockMenu>>();
    const auto command = std::make_unique<Command::Exit>(mockMenu.get());

    EXPECT_CALL(*mockMenu, Exit()).Times(1);

    command->Execute();
}
