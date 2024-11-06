#ifndef REDO_H
#define REDO_H

#include "HistoryCommand.h"

namespace Command
{
    class Redo final : public HistoryCommand
    {
    public:
        explicit Redo(IHistory *history) : HistoryCommand(history) {}

        void Execute() override
        {
            if (m_history->CanRedo())
            {
                m_history->Redo();
            }
        }
    };
} // namespace Command

#endif // REDO_H
