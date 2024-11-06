#include "History.h"
#include "Menu.h"
#include "command/Exit.h"
#include "command/Help.h"
#include "command/InsertParagraph.h"
#include "command/List.h"
#include "command/Redo.h"
#include "command/Undo.h"
#include "document/Document.h"

int main()
{
    const auto history = std::make_unique<History>();
    const auto menu = std::make_unique<Menu>(history.get());
    const auto document = std::make_unique<Document>();

    menu->AddItem("help", "Show instructions", [&]() { return std::make_unique<Command::Help>(menu.get()); });
    menu->AddItem("exit", "Exit from this menu", [&]() { return std::make_unique<Command::Exit>(menu.get()); });
    menu->AddItem("undo", "Undo last command", [&]() { return std::make_unique<Command::Undo>(history.get()); });
    menu->AddItem("redo", "Redo last command", [&]() { return std::make_unique<Command::Redo>(history.get()); });
    menu->AddItem(
        "list", "List all items", [&]() { return std::make_unique<Command::List>(menu.get(), document.get()); }
    );
    menu->AddItem(
        "insert_paragraph", "Insert paragraph. Arguments: <position>|end <text>",
        [&]() { return std::make_unique<Command::InsertParagraph>(document.get(), menu.get()); }
    );

    menu->ShowInstructions();
    menu->Run();

    return 0;
}
