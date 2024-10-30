#include <gtest/gtest.h>

#include "../src/ConstDocumentItem.h"
#include "MockImage.h"
#include "MockParagraph.h"

TEST(ConstDocumentItem, ConstructorWithImageSetsImage)
{
    const std::shared_ptr<const IImage> mockImage = std::make_shared<MockImage>();
    const ConstDocumentItem item(mockImage);
    EXPECT_EQ(item.GetImage(), mockImage);
    EXPECT_EQ(item.GetParagraph(), nullptr);
}

TEST(ConstDocumentItem, ConstructorWithParagraphSetsParagraph)
{
    const std::shared_ptr<const IParagraph> mockParagraph = std::make_shared<MockParagraph>();
    const ConstDocumentItem item(mockParagraph);
    EXPECT_EQ(item.GetParagraph(), mockParagraph);
    EXPECT_EQ(item.GetImage(), nullptr);
}
