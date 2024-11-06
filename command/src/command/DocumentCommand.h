#ifndef DOCUMENTCOMMAND_H
#define DOCUMENTCOMMAND_H

#include "../document/IDocument.h"
#include "IUndoableCommand.h"

class DocumentCommand : public IUndoableCommand
{
public:
    explicit DocumentCommand(IDocument *document) : m_document(document) {}

protected:
    IDocument *m_document;
};

#endif // DOCUMENTCOMMAND_H
