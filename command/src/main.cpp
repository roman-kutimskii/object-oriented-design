#include <memory>

#include "History.h"
#include "Menu.h"
#include "command/Exit.h"

int main()
{
    const auto menu = std::make_unique<Menu>();
    auto history = std::make_unique<History>();

    menu->AddItem("exit", "Exit from this menu", std::make_unique<Command::Exit>(menu.get()));

    menu->ShowInstructions();
    menu->Run();

    return 0;
}
