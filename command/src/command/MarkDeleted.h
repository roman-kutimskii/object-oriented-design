#ifndef MARKDELETED_H
#define MARKDELETED_H

#include "DocumentCommand.h"

class MarkDeleted final : public DocumentCommand
{
public:
    MarkDeleted(std::shared_ptr<IDocument> document, const size_t position) :
        DocumentCommand(std::move(document)),
        m_position(position)
    {
    }

    void Execute() override
    {
        const auto item = m_document->GetItem(m_position).GetImage();
        if (item == nullptr)
        {
            throw std::invalid_argument("Image not found");
        }
        item->SetDeleted(true);
    }

    void Unexecute() override
    {
        const auto item = m_document->GetItem(m_position).GetImage();
        item->SetDeleted(false);
    }

private:
    size_t m_position;
};

#endif // MARKDELETED_H
