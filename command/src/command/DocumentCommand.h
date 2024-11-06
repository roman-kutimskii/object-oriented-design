#ifndef DOCUMENTCOMMAND_H
#define DOCUMENTCOMMAND_H

#include <memory>

#include "../document/IDocument.h"
#include "IUndoableCommand.h"

class DocumentCommand : public IUndoableCommand
{
private:
    std::shared_ptr<IDocument> m_document;
};

#endif // DOCUMENTCOMMAND_H
