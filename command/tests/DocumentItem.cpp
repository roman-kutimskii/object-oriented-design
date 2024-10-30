#include <gtest/gtest.h>

#include "../src/DocumentItem.h"
#include "MockImage.h"
#include "MockParagraph.h"

TEST(DocumentItem, ConstructorWithImageSetsImage)
{
    const std::shared_ptr<IImage> mockImage = std::make_shared<MockImage>();
    DocumentItem item(mockImage);
    EXPECT_EQ(item.GetImage(), mockImage);
    EXPECT_EQ(item.GetParagraph(), nullptr);
}

TEST(DocumentItem, ConstructorWithParagraphSetsParagraph)
{
    const std::shared_ptr<IParagraph> mockParagraph = std::make_shared<MockParagraph>();
    DocumentItem item(mockParagraph);
    EXPECT_EQ(item.GetParagraph(), mockParagraph);
    EXPECT_EQ(item.GetImage(), nullptr);
}
