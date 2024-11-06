#ifndef MENUCOMMAND_H
#define MENUCOMMAND_H

#include "../Menu.h"
#include "ICommand.h"

class MenuCommand : public ICommand
{
public:
    explicit MenuCommand(IMenu *menu) : m_menu(menu){};

protected:
    IMenu *m_menu;
};

#endif // MENUCOMMAND_H
