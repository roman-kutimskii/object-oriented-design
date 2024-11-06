#ifndef MOCKDOCUMENT_H
#define MOCKDOCUMENT_H

#include <gmock/gmock.h>

#include "../src/document/IDocument.h"

class MockDocument : public IDocument
{
public:
    MOCK_METHOD(void, InsertParagraph, (const std::string &text, std::optional<size_t> position), (override));
    MOCK_METHOD(
        void, InsertImage, (const std::string &path, int width, int height, std::optional<size_t> position), (override)
    );
    MOCK_METHOD(size_t, GetItemsCount, (), (const, override));
    MOCK_METHOD(DocumentItem *, GetItem, (size_t position), (override));
    MOCK_METHOD(const DocumentItem *, GetItem, (size_t position), (const, override));
    MOCK_METHOD(void, DeleteItem, (size_t position), (override));
    MOCK_METHOD(const std::string &, GetTitle, (), (const, override));
    MOCK_METHOD(void, SetTitle, (const std::string &title), (override));
    MOCK_METHOD(void, Save, (const std::string &path, const IExporter &exporter), (const, override));
    MOCK_METHOD(void, SetDeleted, (size_t position, bool value), (override));
};

#endif // MOCKDOCUMENT_H
