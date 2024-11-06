#ifndef DOCUMENTCOMMAND_H
#define DOCUMENTCOMMAND_H

#include <memory>

#include "../document/IDocument.h"
#include "IUndoableCommand.h"

class DocumentCommand : public IUndoableCommand
{
public:
    explicit DocumentCommand(std::shared_ptr<IDocument> document) : m_document(std::move(document)) {}

protected:
    std::shared_ptr<IDocument> m_document;
};

#endif // DOCUMENTCOMMAND_H
