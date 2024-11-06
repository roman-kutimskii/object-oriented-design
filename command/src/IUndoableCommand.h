#ifndef IUNDOABLECOMMAND_H
#define IUNDOABLECOMMAND_H

#include "ICommand.h"

class IUndoableCommand : public ICommand
{
public:
    virtual void Unexecute() = 0;
};

#endif // IUNDOABLECOMMAND_H
