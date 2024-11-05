#ifndef IDOCUMENT_H
#define IDOCUMENT_H

#include <optional>
#include <string>

#include "ConstDocumentItem.h"
#include "DocumentItem.h"

class IDocument
{
public:
    virtual ~IDocument() = default;
    virtual void InsertParagraph(const std::string &text, std::optional<size_t> position) = 0;
    virtual void InsertImage(const std::string &path, int width, int height, std::optional<size_t> position) = 0;
    [[nodiscard]] virtual size_t GetItemsCount() const = 0;
    [[nodiscard]] virtual ConstDocumentItem GetItem(size_t index) const = 0;
    virtual DocumentItem GetItem(size_t index) = 0;
    virtual void DeleteItem(size_t index) = 0;
    [[nodiscard]] virtual std::string GetTitle() const = 0;
    virtual void SetTitle(const std::string &title) = 0;
    virtual void Save(const std::string &path) const = 0;
    virtual void MarkDeleted(bool deleted) = 0;
};

#endif // IDOCUMENT_H
