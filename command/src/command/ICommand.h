#ifndef ICOMMAND_H
#define ICOMMAND_H

class ICommand
{
public:
    virtual ~ICommand() = default;
    virtual void Execute() = 0;
};

#endif // ICOMMAND_H
