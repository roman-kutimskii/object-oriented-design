#ifndef MOCKHISTORY_H
#define MOCKHISTORY_H

#include <gmock/gmock.h>

#include "../src/IHistory.h"

class MockHistory : public IHistory
{
public:
    MOCK_METHOD(void, AddCommand, (std::unique_ptr<IUndoableCommand> && command), (override));
    MOCK_METHOD(void, Undo, (), (override));
    MOCK_METHOD(void, Redo, (), (override));
    MOCK_METHOD(bool, CanUndo, (), (const, override));
    MOCK_METHOD(bool, CanRedo, (), (const, override));
};

#endif // MOCKHISTORY_H
