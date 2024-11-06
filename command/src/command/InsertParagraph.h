#ifndef INSERTPARAGRAPH_H
#define INSERTPARAGRAPH_H

#include "DocumentCommand.h"

namespace Command
{
    class InsertParagraph final : public DocumentCommand
    {
    public:
        explicit InsertParagraph(IDocument *document, IMenu *menu) : DocumentCommand(document, menu) {}

        void Execute() override
        {
            if (!m_initialized)
            {
                std::istringstream arguments(m_menu->ReadArguments());
                std::string position;
                getline(arguments, position, ' ');
                if (position == "end")
                {
                    m_position = std::nullopt;
                }
                else
                {
                    m_position = std::stoi(position);
                }
                getline(arguments, m_text);
                m_initialized = true;
            }
            m_document->InsertParagraph(m_text, m_position);
        }

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
        std::optional<size_t> m_position = std::nullopt;
    };
} // namespace Command

#endif // INSERTPARAGRAPH_H
