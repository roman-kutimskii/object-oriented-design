#ifndef HISTORYCOMMAND_H
#define HISTORYCOMMAND_H

#include "../IHistory.h"
#include "ICommand.h"

class HistoryCommand : public ICommand
{
public:
    explicit HistoryCommand(IHistory *history) : m_history(history) {}

protected:
    IHistory *m_history;
};

#endif // HISTORYCOMMAND_H
