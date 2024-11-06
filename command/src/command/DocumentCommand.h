#ifndef DOCUMENTCOMMAND_H
#define DOCUMENTCOMMAND_H

#include "../document/IDocument.h"
#include "IUndoableCommand.h"

class DocumentCommand : public IUndoableCommand
{
public:
    explicit DocumentCommand(IDocument *document, IMenu *menu) : m_document(document), m_menu(menu) {}

protected:
    IDocument *m_document;
    IMenu *m_menu;
    bool m_initialized = false;
};

#endif // DOCUMENTCOMMAND_H
