#ifndef LIST_H
#define LIST_H

#include <iostream>


#include "DocumentCommand.h"

class List : public DocumentCommand
{
public:
    explicit List(std::shared_ptr<IDocument> document) : DocumentCommand(std::move(document)){};

    void Execute() override
    {
        std::cout << "Title: " << m_document->GetTitle() << std::endl;
        const auto itemsCount = m_document->GetItemsCount();
        for (auto i = 0; i < itemsCount; i++)
        {
            std::cout << i + 1 << m_document->GetItem(i).ToString() << std::endl;
        }
    }

    void Unexecute() override {}
};

#endif // LIST_H
