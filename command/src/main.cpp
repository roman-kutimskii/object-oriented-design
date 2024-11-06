#include "History.h"
#include "Menu.h"
#include "command/Exit.h"
#include "command/Help.h"

int main()
{
    const auto menu = std::make_unique<Menu>();
    const auto history = std::make_unique<History>();

    menu->AddItem("help", "Show instructions", std::make_unique<Command::Help>(menu.get()));
    menu->AddItem("exit", "Exit from this menu", std::make_unique<Command::Exit>(menu.get()));

    menu->ShowInstructions();
    menu->Run();

    return 0;
}
