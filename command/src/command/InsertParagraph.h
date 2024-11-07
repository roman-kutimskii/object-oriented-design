#ifndef INSERTPARAGRAPH_H
#define INSERTPARAGRAPH_H

#include <utility>

#include "DocumentCommand.h"

namespace Command
{
    class InsertParagraph final : public DocumentCommand
    {
    public:
        explicit
        InsertParagraph(IDocument *document, std::string text, const std::optional<size_t> position = std::nullopt) :
            DocumentCommand(document),
            m_text(std::move(text)),
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
        std::string m_text;
        std::optional<size_t> m_position;
    };
} // namespace Command

#endif // INSERTPARAGRAPH_H
