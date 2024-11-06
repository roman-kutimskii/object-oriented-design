#include <gtest/gtest.h>

#include "../../src/command/List.h"
#include "../MockDocument.h"
#include "../MockMenu.h"
#include "../MockParagraph.h"


TEST(ListCommandTest, ExecuteCallsMenuAndDocumentMethods)
{
    const auto mockMenu = std::make_unique<testing::NiceMock<MockMenu>>();
    const auto mockDocument = std::make_unique<testing::NiceMock<MockDocument>>();
    auto mockParagraph = std::make_unique<testing::NiceMock<MockParagraph>>();
    static const std::string paragraphText = "Sample text";

    EXPECT_CALL(*mockParagraph, GetText()).WillOnce(testing::ReturnRef(paragraphText));

    const auto documentItem = std::make_unique<DocumentItem>(std::move(mockParagraph));
    const auto command = std::make_unique<Command::List>(mockMenu.get(), mockDocument.get());

    EXPECT_CALL(*mockDocument, GetItem(0)).WillOnce(testing::Return(documentItem.get()));
    EXPECT_CALL(*mockDocument, GetItemsCount()).WillOnce(testing::Return(1));
    EXPECT_CALL(*mockMenu, Write(testing::_)).Times(1);

    command->Execute();
}
