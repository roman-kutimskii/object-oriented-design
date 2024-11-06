#include <gtest/gtest.h>

#include "../src/Menu.h"
#include "MockCommand.h"

TEST(MenuTest, RunWithCustomStreams)
{
    std::istringstream input("test\n");
    std::ostringstream output;
    Menu menu(input, output);

    auto mockCommand = std::make_unique<testing::NiceMock<MockCommand>>();
    testing::NiceMock<MockCommand> *mockCommandPtr = mockCommand.get();

    EXPECT_CALL(*mockCommandPtr, Execute()).Times(1);

    menu.AddItem("test", "Test Command", std::move(mockCommand));
    menu.Run();

    EXPECT_NE(output.str().find('>'), std::string::npos);
}

TEST(MenuTest, ShowInstructionsWithCustomStream)
{
    std::ostringstream output;
    Menu menu(std::cin, output);
    menu.AddItem("test", "Test Command", std::make_unique<testing::NiceMock<MockCommand>>());

    menu.ShowInstructions();

    EXPECT_NE(output.str().find("test: Test Command"), std::string::npos);
}

TEST(MenuTest, UnknownCommandOutputsMessage)
{
    std::istringstream input("unknown\n");
    std::ostringstream output;
    Menu menu(input, output);

    menu.Run();

    EXPECT_NE(output.str().find("Unknown command"), std::string::npos);
}
