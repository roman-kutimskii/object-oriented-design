#ifndef COMMAND_H
#define COMMAND_H

#include <memory>

#include "ICommand.h"
#include "../IDocument.h"

class DocumentCommand : public ICommand
{
public:
    explicit DocumentCommand(std::shared_ptr<IDocument> document) : m_document(std::move(document)) {}

    [[nodiscard]] std::shared_ptr<ICommand> GetPrev() const override { return m_prev; }

    void SetPrev(std::shared_ptr<ICommand> prev) override { m_prev = std::move(prev); }

private:
    std::shared_ptr<ICommand> m_prev;
protected:
    std::shared_ptr<IDocument> m_document;
};

#endif // COMMAND_H
