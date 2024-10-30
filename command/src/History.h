#ifndef HISTORY_H
#define HISTORY_H

#include <memory>
#include <vector>

#include "ICommand.h"

class History
{
public:
    void AddAndExecuteCommand(std::unique_ptr<ICommand> command)
    {
        if (!command)
        {
            throw std::invalid_argument("Command cannot be null");
        }
        command->Execute();
        if (m_currentIndex < m_commands.size())
        {
            m_commands.erase(m_commands.begin() + m_currentIndex, m_commands.end());
        }

        m_commands.push_back(std::move(command));
        m_currentIndex++;

        if (m_commands.size() > m_maxSize)
        {
            m_commands.erase(m_commands.begin());
            m_currentIndex--;
        }
    }

    [[nodiscard]] bool CanUndo() const { return m_currentIndex > 0; }

    void Undo()
    {
        if (!CanUndo())
        {
            throw std::out_of_range("No command to undo");
        }
        m_commands[--m_currentIndex]->Unexecute();
    }

    [[nodiscard]] bool CanRedo() const { return m_currentIndex < m_commands.size(); }

    void Redo()
    {
        if (!CanRedo())
        {
            throw std::out_of_range("No command to redo");
        }
        m_commands[m_currentIndex++]->Execute();
    }

private:
    std::vector<std::unique_ptr<ICommand>> m_commands;
    int m_currentIndex = 0;
    int m_maxSize = 10;
};

#endif // HISTORY_H
