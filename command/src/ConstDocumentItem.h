#ifndef CONSTDOCUMENTITEM_H
#define CONSTDOCUMENTITEM_H

#include <memory>

#include "IImage.h"
#include "IParagraph.h"

class ConstDocumentItem
{
public:
    explicit ConstDocumentItem(std::shared_ptr<const IImage> image) : m_image(std::move(image)){};
    explicit ConstDocumentItem(std::shared_ptr<const IParagraph> paragraph) : m_paragraph(std::move(paragraph)){};

    [[nodiscard]] std::shared_ptr<const IImage> GetImage() const { return m_image; }

    [[nodiscard]] std::shared_ptr<const IParagraph> GetParagraph() const { return m_paragraph; }

    [[nodiscard]] std::string ToString() const
    {
        std::stringstream ss;
        if (m_image)
        {
            ss << "Image: " << m_image->GetWidth() << " " << m_image->GetHeight() << " " << m_image->GetPath();
        }
        else if (m_paragraph)
        {
            ss << "Paragraph: " << m_paragraph->GetText();
        }
        return ss.str();
    }

private:
    std::shared_ptr<const IImage> m_image;
    std::shared_ptr<const IParagraph> m_paragraph;
};

#endif // CONSTDOCUMENTITEM_H
