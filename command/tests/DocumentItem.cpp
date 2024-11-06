#include <gtest/gtest.h>

#include "../src/document/DocumentItem.h"
#include "MockImage.h"
#include "MockParagraph.h"

using testing::NiceMock;
using testing::Return;
using testing::ReturnRef;

TEST(DocumentItemTest, GetImageReturnsCorrectImage)
{
    auto mockImage = std::make_unique<NiceMock<MockImage>>();
    static const std::string imagePath = "path/to/image.png";

    EXPECT_CALL(*mockImage, GetWidth()).WillOnce(Return(640));
    EXPECT_CALL(*mockImage, GetHeight()).WillOnce(Return(480));
    EXPECT_CALL(*mockImage, GetPath()).WillOnce(ReturnRef(imagePath));

    DocumentItem item(std::move(mockImage));
    const IImage *image = item.GetImage();

    ASSERT_NE(image, nullptr);
    EXPECT_EQ(image->GetWidth(), 640);
    EXPECT_EQ(image->GetHeight(), 480);
    EXPECT_EQ(image->GetPath(), "path/to/image.png");
}

TEST(DocumentItemTest, GetParagraphReturnsCorrectParagraph)
{
    auto mockParagraph = std::make_unique<NiceMock<MockParagraph>>();
    static const std::string paragraphText = "Sample text";

    EXPECT_CALL(*mockParagraph, GetText()).WillOnce(ReturnRef(paragraphText));

    DocumentItem item(std::move(mockParagraph));
    const IParagraph *paragraph = item.GetParagraph();

    ASSERT_NE(paragraph, nullptr);
    EXPECT_EQ(paragraph->GetText(), "Sample text");
}

TEST(DocumentItemTest, ToStringReturnsCorrectStringForImage)
{
    auto mockImage = std::make_unique<NiceMock<MockImage>>();
    static const std::string imagePath = "path/to/image.png";

    EXPECT_CALL(*mockImage, GetWidth()).WillOnce(Return(640));
    EXPECT_CALL(*mockImage, GetHeight()).WillOnce(Return(480));
    EXPECT_CALL(*mockImage, GetPath()).WillOnce(ReturnRef(imagePath));

    const DocumentItem item(std::move(mockImage));
    const std::string expected = "Image: 640 480 path/to/image.png";
    EXPECT_EQ(item.ToString(), expected);
}

TEST(DocumentItemTest, ToStringReturnsCorrectStringForParagraph)
{
    auto mockParagraph = std::make_unique<NiceMock<MockParagraph>>();
    static const std::string paragraphText = "Sample text";

    EXPECT_CALL(*mockParagraph, GetText()).WillOnce(ReturnRef(paragraphText));

    const DocumentItem item(std::move(mockParagraph));
    const std::string expected = "Paragraph: Sample text";
    EXPECT_EQ(item.ToString(), expected);
}
