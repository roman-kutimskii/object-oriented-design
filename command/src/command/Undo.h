#ifndef UNDO_H
#define UNDO_H

#include "HistoryCommand.h"

namespace Command
{
    class Undo final : public HistoryCommand
    {
    public:
        explicit Undo(IHistory *history) : HistoryCommand(history) {}

        void Execute() override
        {
            if (m_history->CanUndo())
            {
                m_history->Undo();
            }
        }
    };
} // namespace Command

#endif // UNDO_H
