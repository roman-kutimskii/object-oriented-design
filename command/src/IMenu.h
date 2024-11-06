#ifndef IMENU_H
#define IMENU_H

#include <memory>
#include <string>
#include <functional>

#include "command/ICommand.h"

class IMenu
{
public:
    virtual ~IMenu() = default;
    virtual void AddItem(
        const std::string &shortcut, const std::string &description,
        std::function<std::unique_ptr<ICommand>()> commandConstructor
    ) = 0;
    virtual void Run() = 0;
    virtual void ShowInstructions() const = 0;
    virtual void Exit() = 0;
    virtual void Write(const std::string &text) const = 0;
    [[nodiscard]] virtual std::string ReadArguments() const = 0;
};

#endif // IMENU_H
