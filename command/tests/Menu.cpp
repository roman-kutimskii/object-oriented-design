#include <gtest/gtest.h>

#include "../src/Menu.h"
#include "MockCommand.h"
#include "MockHistory.h"

TEST(MenuTest, RunWithCustomStreams)
{
    const auto mockHistory = std::make_shared<MockHistory>();
    std::istringstream input("test\n");
    std::ostringstream output;
    Menu menu(mockHistory.get(), input, output);

    auto mockCommand = std::make_unique<testing::NiceMock<MockCommand>>();
    testing::NiceMock<MockCommand> *mockCommandPtr = mockCommand.get();

    EXPECT_CALL(*mockCommandPtr, Execute()).Times(1);

    menu.AddItem("test", "Test Command", [&]() { return std::move(mockCommand); });
    menu.Run();

    EXPECT_NE(output.str().find('>'), std::string::npos);
}

TEST(MenuTest, ShowInstructionsWithCustomStream)
{
    const auto mockHistory = std::make_shared<MockHistory>();
    std::ostringstream output;
    Menu menu(mockHistory.get(), std::cin, output);
    menu.AddItem("test", "Test Command", []() { return std::make_unique<testing::NiceMock<MockCommand>>(); });

    menu.ShowInstructions();

    EXPECT_NE(output.str().find("test: Test Command"), std::string::npos);
}

TEST(MenuTest, UnknownCommandOutputsMessage)
{
    const auto mockHistory = std::make_shared<MockHistory>();
    std::istringstream input("unknown\n");
    std::ostringstream output;
    std::ostringstream errors;
    Menu menu(mockHistory.get(), input, output, errors);

    menu.Run();

    EXPECT_NE(errors.str().find("Unknown command"), std::string::npos);
}
