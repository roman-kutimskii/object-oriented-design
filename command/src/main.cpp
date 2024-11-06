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
    const auto menu = std::make_unique<Menu>();
    const auto history = std::make_unique<History>();
    const auto document = std::make_unique<Document>();

    menu->AddItem("help", "Show instructions", std::make_unique<Command::Help>(menu.get()));
    menu->AddItem("exit", "Exit from this menu", std::make_unique<Command::Exit>(menu.get()));
    menu->AddItem("undo", "Undo last command", std::make_unique<Command::Undo>(history.get()));
    menu->AddItem("redo", "Redo last command", std::make_unique<Command::Redo>(history.get()));
    menu->AddItem("list", "List all items", std::make_unique<Command::List>(menu.get(), document.get()));
    menu->AddItem(
        "insert_paragraph", "Insert paragraph. Arguments: <position>|end <text>",
        std::make_unique<Command::InsertParagraph>(document.get(), menu.get())
    );

    menu->ShowInstructions();
    menu->Run();

    return 0;
}
