#ifndef HELP_H
#define HELP_H
#include "MenuCommand.h"

namespace Command
{
    class Help final : public MenuCommand
    {
    public:
        explicit Help(IMenu *menu) : MenuCommand(menu) {}

        void Execute() override { m_menu->ShowInstructions(); };
    };
} // namespace Command

#endif // HELP_H
