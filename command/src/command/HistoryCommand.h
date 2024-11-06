#ifndef HISTORYCOMMAND_H
#define HISTORYCOMMAND_H

#include <memory>

#include "../History.h"
#include "ICommand.h"

class HistoryCommand : public ICommand
{
public:
    explicit HistoryCommand(std::shared_ptr<History> history) : m_history(std::move(history)) {}

protected:
    std::shared_ptr<History> m_history;
};

#endif // HISTORYCOMMAND_H
