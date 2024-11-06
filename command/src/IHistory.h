#ifndef IHISTORY_H
#define IHISTORY_H

#include <memory>

#include "command/IUndoableCommand.h"

class IHistory
{
public:
    virtual ~IHistory() = default;
    virtual void AddCommand(std::unique_ptr<IUndoableCommand> &&command) = 0;
    virtual void Undo() = 0;
    virtual void Redo() = 0;
    [[nodiscard]] virtual bool CanUndo() const = 0;
    [[nodiscard]] virtual bool CanRedo() const = 0;
};

#endif // IHISTORY_H
