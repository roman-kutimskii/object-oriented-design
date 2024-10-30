#ifndef INSERTIMAGE_H
#define INSERTIMAGE_H

#include "DocumentCommand.h"

class InsertImage final : DocumentCommand
{
public:
    InsertImage(
        std::shared_ptr<IDocument> document, const std::string &path, const int width, const int height,
        const std::optional<size_t> position = std::nullopt
    ) :
        DocumentCommand(std::move(document)),
        m_position(position),
        m_width(width),
        m_height(height),
        m_path(path)
    {
    }

    void Execute() override { m_document->InsertImage(m_path, m_width, m_height, m_position); }

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
    std::optional<size_t> m_position;
    int m_width;
    int m_height;
    const std::string &m_path;
    std::string m_copyPath;
};

#endif // INSERTIMAGE_H
