#ifndef MOCKMENU_H
#define MOCKMENU_H

#include <gmock/gmock.h>

#include "../src/IMenu.h"

class MockMenu : public IMenu
{
public:
    MOCK_METHOD(
        void, AddItem,
        (const std::string &shortcut, const std::string &description, std::unique_ptr<ICommand> &&command), (override)
    );
    MOCK_METHOD(void, Run, (), (override));
    MOCK_METHOD(void, ShowInstructions, (), (const, override));
    MOCK_METHOD(void, Exit, (), (override));
};

#endif // MOCKMENU_H