#ifndef IUNDOABLECOMMAND_H
#define IUNDOABLECOMMAND_H

#include "ICommand.h"

class IUndoableCommand : public ICommand
{
public:
    virtual void Unexecute() = 0;

    [[nodiscard]] bool CanUndo() const override { return true; }
};

#endif // IUNDOABLECOMMAND_H
