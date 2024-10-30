#include <gtest/gtest.h>

#include "../../src/command/DocumentCommand.h"
#include "../MockDocument.h"
#include "MockCommand.h"

class ConcreteDocumentCommand final : public DocumentCommand
{
public:
    explicit ConcreteDocumentCommand(std::shared_ptr<IDocument> document) : DocumentCommand(std::move(document)){};
    void Execute() override{};
    void Unexecute() override{};
};

TEST(DocumentCommand, GetPrevInitiallyNull)
{
    auto mockDocument = std::make_shared<MockDocument>();
    const auto documentCommand = std::make_unique<ConcreteDocumentCommand>(mockDocument);
    EXPECT_EQ(documentCommand->GetPrev(), nullptr);
}

TEST(DocumentCommand, SetPrevUpdatesPrevCommand)
{
    auto mockDocument = std::make_shared<MockDocument>();
    const auto mockPrevCommand = std::make_shared<MockCommand>();
    const auto documentCommand = std::make_unique<ConcreteDocumentCommand>(mockDocument);
    documentCommand->SetPrev(mockPrevCommand);
    EXPECT_EQ(documentCommand->GetPrev(), mockPrevCommand);
}
