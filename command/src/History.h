#ifndef HISTORY_H
#define HISTORY_H

#include <memory>
#include <vector>

#include "command/IUndoableCommand.h"

class History
{
public:
    void AddCommand(std::unique_ptr<IUndoableCommand> &&command)
    {
        if (m_undoStack.size() >= m_maxSize)
        {
            m_undoStack.erase(m_undoStack.begin());
        }
        m_undoStack.push_back(std::move(command));
        m_redoStack.clear();
    }

    void Undo()
    {
        if (!CanUndo())
        {
            throw std::out_of_range("No command to undo");
        }
        auto command = std::move(m_undoStack.back());
        m_undoStack.pop_back();
        command->Unexecute();
        if (m_redoStack.size() >= m_maxSize)
        {
            m_redoStack.erase(m_redoStack.begin());
        }
        m_redoStack.push_back(std::move(command));
    }

    void Redo()
    {
        if (!CanRedo())
        {
            throw std::out_of_range("No command to redo");
        }
        auto command = std::move(m_redoStack.back());
        m_redoStack.pop_back();
        command->Execute();
        if (m_undoStack.size() >= m_maxSize)
        {
            m_undoStack.erase(m_undoStack.begin());
        }
        m_undoStack.push_back(std::move(command));
    }

    [[nodiscard]] bool CanUndo() const { return !m_undoStack.empty(); }

    [[nodiscard]] bool CanRedo() const { return !m_redoStack.empty(); }


private:
    std::vector<std::unique_ptr<IUndoableCommand>> m_undoStack;
    std::vector<std::unique_ptr<IUndoableCommand>> m_redoStack;
    int m_maxSize = 10;
};

#endif // HISTORY_H