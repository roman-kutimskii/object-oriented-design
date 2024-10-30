#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <memory>

class ICommand
{
public:
    virtual ~ICommand() = default;
    virtual void Execute() = 0;
    virtual void Unexecute() = 0;
    [[nodiscard]] virtual std::shared_ptr<ICommand> GetPrev() const = 0;
    virtual void SetPrev(std::shared_ptr<ICommand> command) = 0;
};

#endif // ICOMMAND_H
