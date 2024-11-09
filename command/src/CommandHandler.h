#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include "IHistory.h"
#include "IMenu.h"
#include "command/Exit.h"
#include "command/Help.h"
#include "command/InsertParagraph.h"
#include "command/List.h"
#include "command/Redo.h"
#include "command/Undo.h"
#include "document/IDocument.h"

class CommandHandler
{
public:
    CommandHandler(IMenu *menu, IHistory *history, IDocument *document)
    {
        menu->AddItem("help", "Show instructions", [=]() { return std::make_unique<Command::Help>(menu); });
        menu->AddItem("exit", "Exit from this menu", [=]() { return std::make_unique<Command::Exit>(menu); });
        menu->AddItem("undo", "Undo last command", [=]() { return std::make_unique<Command::Undo>(history); });
        menu->AddItem("redo", "Redo last command", [=]() { return std::make_unique<Command::Redo>(history); });
        menu->AddItem("list", "List all items", [=]() { return std::make_unique<Command::List>(menu, document); });
        menu->AddItem(
            "insert_paragraph", "Insert paragraph. Arguments: <position>|end <text>", InsertParagraph(document, menu)
        );
    }

private:
    static std::function<std::unique_ptr<ICommand>()> InsertParagraph(IDocument *document, const IMenu *menu)
    {
        return [=]()
        {
            std::istringstream arguments(menu->ReadArguments());
            std::string positionStr;
            std::optional<size_t> position;
            getline(arguments, positionStr, ' ');
            if (positionStr == "end")
            {
                position = std::nullopt;
            }
            else
            {
                position = std::stoi(positionStr);
            }
            std::string text;
            getline(arguments, text);
            return std::make_unique<Command::InsertParagraph>(document, text, position);
        };
    };
};

#endif // COMMANDHANDLER_H
