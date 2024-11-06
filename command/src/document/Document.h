#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <vector>

#include "IDocument.h"
#include "Image.h"
#include "Paragraph.h"

class Document final : public IDocument
{
public:
    void InsertParagraph(const std::string &text, const std::optional<size_t> position) override
    {
        auto paragraph = std::make_unique<Paragraph>(text);
        auto item = std::make_unique<DocumentItem>(std::move(paragraph));

        if (position.has_value())
        {
            if (position.value() >= m_items.size())
            {
                throw std::out_of_range("Position out of range");
            }
            m_items.insert(m_items.begin() + static_cast<int>(position.value()), std::move(item));
        }
        else
        {
            m_items.push_back(std::move(item));
        }
    }

    void InsertImage(const std::string &path, const int width, const int height, const std::optional<size_t> position) override
    {
        auto image = std::make_unique<Image>(path, width, height);
        auto item = std::make_unique<DocumentItem>(std::move(image));

        if (position.has_value())
        {
            if (position.value() >= m_items.size())
            {
                throw std::out_of_range("Position out of range");
            }
            m_items.insert(m_items.begin() + static_cast<int>(position.value()), std::move(item));
        }
        else
        {
            m_items.push_back(std::move(item));
        }
    }

    [[nodiscard]] size_t GetItemsCount() const override { return m_items.size(); }

    [[nodiscard]] const std::string &GetTitle() const override { return m_title; }

    void SetTitle(const std::string &title) override { m_title = title; }

    [[nodiscard]] const DocumentItem *GetItem(const size_t position) const override
    {
        if (position >= m_items.size())
        {
            throw std::out_of_range("Position out of range");
        }
        return m_items[position].get();
    }

    DocumentItem *GetItem(const size_t position) override
    {
        if (position >= m_items.size())
        {
            throw std::out_of_range("Position out of range");
        }
        return m_items[position].get();
    }

    void DeleteItem(const size_t position) override
    {
        if (position >= m_items.size())
        {
            throw std::out_of_range("Position out of range");
        }
        m_items.erase(m_items.begin() + static_cast<int>(position));
    }

    void Save(const std::string &path, const IExporter *exporter) const override { exporter->Export(path, m_items); }

    void SetDeleted(const size_t position, const bool value) override
    {
        if (position >= m_items.size())
        {
            throw std::out_of_range("Position out of range");
        }
        IImage *image = m_items[position]->GetImage();
        if (image == nullptr)
        {
            throw std::runtime_error("Item is not an Image");
        }
        image->SetDeleted(value);
    }

private:
    std::vector<std::unique_ptr<DocumentItem>> m_items;
    std::string m_title;
};

#endif // DOCUMENT_H
