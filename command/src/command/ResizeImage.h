#ifndef RESIZEIMAGE_H
#define RESIZEIMAGE_H
#include "DocumentCommand.h"

class ResizeImage final : public DocumentCommand
{
public:
    ResizeImage(std::shared_ptr<IDocument> document, const int width, const int height, const size_t position) :
        DocumentCommand(std::move(document)),
        m_position(position),
        m_width(width),
        m_height(height)
    {
    }

    void Execute() override
    {
        const auto item = m_document->GetItem(m_position).GetImage();
        if (item == nullptr)
        {
            throw std::invalid_argument("Image not found");
        }
        m_prevWidth = item->GetWidth();
        m_prevHeight = item->GetHeight();
        item->Resize(m_width, m_height);
    }

    void Unexecute() override
    {
        const auto item = m_document->GetItem(m_position).GetImage();
        item->Resize(m_prevWidth, m_prevHeight);
    }

private:
    size_t m_position;
    int m_width;
    int m_height;
    int m_prevWidth = 0;
    int m_prevHeight = 0;
};

#endif // RESIZEIMAGE_H
