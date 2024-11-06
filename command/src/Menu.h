#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "IHistory.h"
#include "IMenu.h"
#include "command/ICommand.h"

class Menu final : public IMenu
{
public:
    explicit Menu(
        IHistory *history, std::istream &input = std::cin, std::ostream &output = std::cout,
        std::ostream &errput = std::cerr
    ) :
        m_history(history),
        m_input(input),
        m_output(output),
        m_errors(errput)
    {
    }

    void AddItem(
        const std::string &shortcut, const std::string &description,
        std::function<std::unique_ptr<ICommand>()> commandConstructor
    ) override
    {
        m_items.emplace_back(std::make_unique<Item>(shortcut, description, std::move(commandConstructor)));
    }

    void Run() override
    {
        std::string command;
        while (m_output << ">" && std::getline(m_input, command) && ExecuteCommand(command))
        {
        }
    }

    void ShowInstructions() const override
    {
        m_output << "Commands list" << std::endl;
        for (int i = 0; i < m_items.size(); i++)
        {
            m_output << i + 1 << ". " << m_items[i]->shortcut << ": " << m_items[i]->description << std::endl;
        }
    }

    void Exit() override { m_exit = true; }

    void Write(const std::string &text) const override { m_output << text; }

    [[nodiscard]] std::string ReadArguments() const override
    {
        std::string result;
        m_output << "Enter arguments:" << std::endl;
        m_output << "~";
        std::getline(m_input, result);
        return result;
    }

private:
    struct Item
    {
        Item(
            std::string shortcut, std::string description, std::function<std::unique_ptr<ICommand>()> commandConstructor
        ) :
            shortcut(std::move(shortcut)),
            description(std::move(description)),
            commandConstructor(std::move(commandConstructor))
        {
        }

        std::string shortcut;
        std::string description;
        std::function<std::unique_ptr<ICommand>()> commandConstructor;
    };

    bool ExecuteCommand(const std::string &command)
    {
        m_exit = false;
        const auto it = std::ranges::find_if(m_items, [&](auto &item) { return item->shortcut == command; });
        if (it != m_items.end())
        {
            if (auto commandPtr = it->get()->commandConstructor())
            {
                commandPtr->Execute();
                if (commandPtr->CanUndo())
                {
                    m_history->AddCommand(
                        std::unique_ptr<IUndoableCommand>(static_cast<IUndoableCommand *>(commandPtr.release()))
                    );
                }
                else
                {
                    m_errors << "Command is not undoable" << std::endl;
                }
            }
            else
            {
                m_errors << "Failed to create command" << std::endl;
            }
        }
        else
        {
            m_errors << "Unknown command" << std::endl;
        }

        return !m_exit;
    }

    bool m_exit = false;
    IHistory *m_history;
    std::istream &m_input;
    std::ostream &m_output;
    std::ostream &m_errors;
    std::vector<std::unique_ptr<Item>> m_items;
};

#endif // MENU_H
