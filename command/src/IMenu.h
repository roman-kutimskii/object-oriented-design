#ifndef IMENU_H
#define IMENU_H

#include <memory>
#include <string>

#include "command/ICommand.h"

class IMenu
{
public:
    virtual ~IMenu() = default;
    virtual void
    AddItem(const std::string &shortcut, const std::string &description, std::unique_ptr<ICommand> &&command)
        = 0;
    virtual void Run() = 0;
    virtual void ShowInstructions() const = 0;
    virtual void Exit() = 0;
};

#endif // IMENU_H