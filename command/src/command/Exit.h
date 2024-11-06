#ifndef EXIT_H
#define EXIT_H

#include "MenuCommand.h"

namespace Command
{
    class Exit final : public MenuCommand
    {
    public:
        explicit Exit(IMenu *menu) : MenuCommand(menu) {}

        void Execute() override { m_menu->Exit(); }
    };
} // namespace Command

#endif // EXIT_H
