#ifndef LIST_H
#define LIST_H

#include <sstream>

#include "../document/IDocument.h"
#include "MenuCommand.h"

namespace Command
{
    class List final : public MenuCommand
    {
    public:
        explicit List(IMenu *menu, IDocument *document) : MenuCommand(menu), m_document(document) {}

        void Execute() override
        {
            std::ostringstream oss;
            oss << "List of items" << std::endl;
            const auto count = m_document->GetItemsCount();
            for (auto i = 0; i < count; ++i)
            {
                oss << m_document->GetItem(i)->ToString() << std::endl;
            }
            m_menu->Write(oss.str());
        }

    private:
        IDocument *m_document;
    };
} // namespace Command

#endif // LIST_H
