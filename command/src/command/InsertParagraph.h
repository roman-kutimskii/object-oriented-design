#ifndef INSERTPARAGRAPH_H
#define INSERTPARAGRAPH_H

#include "DocumentCommand.h"

class InsertParagraph final : public DocumentCommand
{
public:
    InsertParagraph(
        std::shared_ptr<IDocument> document, const std::string &text,
        const std::optional<size_t> position = std::nullopt
    ) :
        DocumentCommand(std::move(document)),
        m_text(text),
        m_position(position)
    {
    }

    void Execute() override { m_document->InsertParagraph(m_text, m_position); }

    void Unexecute() override
    {
        if (m_position.has_value())
        {
            m_document->DeleteItem(m_position.value());
        }
        else
        {
            m_document->DeleteItem(m_document->GetItemsCount() - 1);
        }
    }

private:
    const std::string &m_text;
    std::optional<size_t> m_position;
};

#endif // INSERTPARAGRAPH_H
