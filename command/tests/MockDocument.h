#ifndef MOCKDOCUMENT_H
#define MOCKDOCUMENT_H

#include <gmock/gmock.h>

#include "../src/IDocument.h"

class MockDocument final : public IDocument
{
public:
    MOCK_METHOD(void, InsertParagraph, (const std::string &text, std::optional<size_t> position), (override));
    MOCK_METHOD(
        void, InsertImage, (const std::string &path, int width, int height, std::optional<size_t> position), (override)
    );
    MOCK_METHOD(size_t, GetItemsCount, (), (const, override));
    MOCK_METHOD(ConstDocumentItem, GetItem, (size_t index), (const, override));
    MOCK_METHOD(DocumentItem, GetItem, (size_t index), (override));
    MOCK_METHOD(void, DeleteItem, (size_t index), (override));
    MOCK_METHOD(std::string, GetTitle, (), (const, override));
    MOCK_METHOD(void, SetTitle, (const std::string &title), (override));
    MOCK_METHOD(void, Save, (const std::string &path), (const, override));
    MOCK_METHOD(void, MarkDeleted, (bool deleted), (override));
};

#endif // MOCKDOCUMENT_H
