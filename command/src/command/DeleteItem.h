#ifndef DELETEITEM_H
#define DELETEITEM_H

#include "DocumentCommand.h"

class DeleteItem final : public DocumentCommand
{
public:
    DeleteItem(std::shared_ptr<IDocument> document, const size_t position) :
        DocumentCommand(std::move(document)),
        m_position(position)
    {
    }

    void Execute() override
    {
        if (m_document->GetItem(m_position).GetImage() != nullptr)
        {
            m_document->MarkDeleted(m_position);
            m_deleted = true;
        }
        else if (m_document->GetItem(m_position).GetParagraph() != nullptr)
        {
            m_deletedItem = m_document->DeleteItem(m_position);
        }
    }

    void Unexecute() override
    {
        if (m_deletedItem->GetImage() != nullptr)
        {
            const auto image = m_deletedItem->GetImage();
            m_document->MarkDeleted(m_position);
        }
        else if (m_deletedItem->GetParagraph() != nullptr)
        {
            const auto paragraph = m_deletedItem->GetParagraph();
            m_document->InsertParagraph(paragraph->GetText(), m_position);
        }
    }

    ~DeleteItem() override
    {
        if (m_deleted)
        {
            m_document->DeleteItem(m_position);
        }
    };


private:
    std::unique_ptr<ConstDocumentItem> m_deletedItem;
    size_t m_position;
    bool m_deleted = false;
};

#endif // DELETEITEM_H
