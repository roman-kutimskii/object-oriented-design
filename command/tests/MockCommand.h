#ifndef MOCKCOMMAND_H
#define MOCKCOMMAND_H

#include <gmock/gmock.h>

#include "../src/ICommand.h"

class MockCommand final : public ICommand
{
public:
    MOCK_METHOD(void, Execute, (), (override));
    MOCK_METHOD(void, Unexecute, (), (override));
    MOCK_METHOD(std::shared_ptr<ICommand>, GetPrev, (), (const, override));
    MOCK_METHOD(void, SetPrev, (std::shared_ptr<ICommand> commnad), (override));
};

#endif // MOCKCOMMAND_H
