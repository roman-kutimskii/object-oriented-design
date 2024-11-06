#ifndef MOCKUNDOABLECOMMAND_H
#define MOCKUNDOABLECOMMAND_H

#include "../src/command/IUndoableCommand.h"
#include "MockCommand.h"

class MockUndoableCommand : public MockCommand, public IUndoableCommand
{
public:
    MOCK_METHOD(void, Unexecute, (), (override));
};

#endif // MOCKUNDOABLECOMMAND_H
