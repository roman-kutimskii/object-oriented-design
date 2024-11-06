#ifndef HISTORYCOMMAND_H
#define HISTORYCOMMAND_H

#include <memory>

#include "../History.h"
#include "ICommand.h"

class HistoryCommand : public ICommand
{
private:
    std::shared_ptr<History> m_history;
};

#endif // HISTORYCOMMAND_H
