#ifndef MOCKCOMMAND_H
#define MOCKCOMMAND_H

#include <gmock/gmock.h>

#include "../src/command/ICommand.h"

class MockCommand : public ICommand
{
public:
    MOCK_METHOD(void, Execute, (), (override));
};

#endif // MOCKCOMMAND_H
