#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "IMenu.h"
#include "command/ICommand.h"

class Menu final : public IMenu
{
public:
    explicit Menu(std::istream &input = std::cin, std::ostream &output = std::cout) : m_input(input), m_output(output)
    {
    }

    void
    AddItem(const std::string &shortcut, const std::string &description, std::unique_ptr<ICommand> &&command) override
    {
        m_items.emplace_back(std::make_unique<Item>(shortcut, description, std::move(command)));
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

    void Write(const std::string &text) const override { m_output << text << std::endl; }

private:
    struct Item
    {
        Item(std::string shortcut, std::string description, std::unique_ptr<ICommand> &&command) :
            shortcut(std::move(shortcut)),
            description(std::move(description)),
            command(std::move(command))
        {
        }

        std::string shortcut;
        std::string description;
        std::unique_ptr<ICommand> command;
    };

    bool ExecuteCommand(const std::string &command)
    {
        m_exit = false;
        const auto it = std::ranges::find_if(m_items, [&](auto &item) { return item->shortcut == command; });
        if (it != m_items.end())
        {
            it->get()->command->Execute();
        }
        else
        {
            m_output << "Unknown command" << std::endl;
        }

        return !m_exit;
    }

    bool m_exit = false;
    std::istream &m_input;
    std::ostream &m_output;
    std::vector<std::unique_ptr<Item>> m_items;
};

#endif // MENU_H
