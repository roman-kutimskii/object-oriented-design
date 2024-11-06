#ifndef DOCUMENTITEM_H
#define DOCUMENTITEM_H

#include <memory>
#include <sstream>

#include "IImage.h"
#include "IParagraph.h"

class DocumentItem
{
public:
    explicit DocumentItem(std::unique_ptr<IImage> &&image) : m_image(std::move(image)) {}

    explicit DocumentItem(std::unique_ptr<IParagraph> &&paragraph) : m_paragraph(std::move(paragraph)) {}

    IImage *GetImage() { return m_image.get(); }

    [[nodiscard]] const IImage *GetImage() const { return m_image.get(); }

    IParagraph *GetParagraph() { return m_paragraph.get(); }

    [[nodiscard]] const IParagraph *GetParagraph() const { return m_paragraph.get(); }

    [[nodiscard]] std::string ToString() const
    {
        std::stringstream ss;
        if (m_image != nullptr)
        {
            ss << "Image: " << m_image->GetWidth() << " " << m_image->GetHeight() << " " << m_image->GetPath();
        }
        else if (m_paragraph != nullptr)
        {
            ss << "Paragraph: " << m_paragraph->GetText();
        }
        return ss.str();
    }

private:
    std::unique_ptr<IImage> m_image;
    std::unique_ptr<IParagraph> m_paragraph;
};

#endif // DOCUMENTITEM_H
