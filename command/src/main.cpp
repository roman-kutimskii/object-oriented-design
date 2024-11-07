#include "CommandHandler.h"
#include "History.h"
#include "Menu.h"
#include "document/Document.h"

int main()
{
    const auto history = std::make_unique<History>();
    const auto menu = std::make_unique<Menu>(history.get());
    const auto document = std::make_unique<Document>();
    const auto commandProcessor = std::make_unique<CommandHandler>(menu.get(), history.get(), document.get());

    menu->ShowInstructions();
    menu->Run();

    return 0;
}
