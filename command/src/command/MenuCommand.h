#ifndef MENUCOMMAND_H
#define MENUCOMMAND_H

#include <memory>

#include "../Menu.h"
#include "ICommand.h"

class MenuCommand : public ICommand
{
private:
    std::shared_ptr<Menu> m_menu;
};

#endif // MENUCOMMAND_H
