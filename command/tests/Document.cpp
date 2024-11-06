#include <gtest/gtest.h>

#include "../src/document/Document.h"
#include "MockExporter.h"

class DocumentTest : public testing::Test
{
protected:
    Document doc;
};

TEST_F(DocumentTest, InsertParagraphAtEnd)
{
    doc.InsertParagraph("First paragraph", std::nullopt);
    EXPECT_EQ(doc.GetItemsCount(), 1);
    EXPECT_EQ(doc.GetItem(0)->GetParagraph()->GetText(), "First paragraph");
}

TEST_F(DocumentTest, InsertParagraphAtPosition)
{
    doc.InsertParagraph("First paragraph", std::nullopt);
    doc.InsertParagraph("Second paragraph", std::nullopt);
    doc.InsertParagraph("Inserted paragraph", 1);

    EXPECT_EQ(doc.GetItemsCount(), 3);
    EXPECT_EQ(doc.GetItem(1)->GetParagraph()->GetText(), "Inserted paragraph");
}

TEST_F(DocumentTest, InsertParagraphOutOfRange)
{
    doc.InsertParagraph("First paragraph", std::nullopt);

    EXPECT_THROW(doc.InsertParagraph("Out of range paragraph", 5), std::out_of_range);
}

TEST_F(DocumentTest, InsertMultipleParagraphs)
{
    doc.InsertParagraph("First paragraph", std::nullopt);
    doc.InsertParagraph("Second paragraph", std::nullopt);
    doc.InsertParagraph("Third paragraph", std::nullopt);

    EXPECT_EQ(doc.GetItemsCount(), 3);
    EXPECT_EQ(doc.GetItem(0)->GetParagraph()->GetText(), "First paragraph");
    EXPECT_EQ(doc.GetItem(1)->GetParagraph()->GetText(), "Second paragraph");
    EXPECT_EQ(doc.GetItem(2)->GetParagraph()->GetText(), "Third paragraph");
}

TEST_F(DocumentTest, InsertImageIncreasesItemCount)
{
    doc.InsertImage("path/to/image.png", 800, 600, std::nullopt);
    EXPECT_EQ(doc.GetItemsCount(), 1);
}

TEST_F(DocumentTest, InsertImageAtSpecificPosition)
{
    doc.InsertParagraph("First paragraph", std::nullopt);
    doc.InsertImage("path/to/image.png", 800, 600, 0);
    EXPECT_EQ(doc.GetItemsCount(), 2);
    const DocumentItem *item = doc.GetItem(0);
    ASSERT_NE(item, nullptr);
    const IImage *image = item->GetImage();
    ASSERT_NE(image, nullptr);
    EXPECT_EQ(image->GetPath(), "path/to/image.png");
}

TEST_F(DocumentTest, InsertImageOutOfRangeThrows)
{
    EXPECT_THROW(doc.InsertImage("path/to/image.png", 800, 600, 1), std::out_of_range);
}

TEST_F(DocumentTest, GetItemsCountInitiallyZero) { EXPECT_EQ(doc.GetItemsCount(), 0); }

TEST_F(DocumentTest, SetAndGetTitle)
{
    const std::string title = "My Document";
    doc.SetTitle(title);
    EXPECT_EQ(doc.GetTitle(), title);
}

TEST_F(DocumentTest, GetItemThrowsOutOfRange) { EXPECT_THROW(doc.GetItem(0), std::out_of_range); }

TEST_F(DocumentTest, InsertParagraphIncreasesItemCount)
{
    doc.InsertParagraph("Test paragraph", std::nullopt);
    EXPECT_EQ(doc.GetItemsCount(), 1);
}

TEST_F(DocumentTest, GetItemReturnsCorrectItem)
{
    const std::string paragraphText = "Test paragraph";
    doc.InsertParagraph(paragraphText, std::nullopt);
    const DocumentItem *item = doc.GetItem(0);
    ASSERT_NE(item, nullptr);
    const IParagraph *paragraph = item->GetParagraph();
    ASSERT_NE(paragraph, nullptr);
    EXPECT_EQ(paragraph->GetText(), paragraphText);
}

TEST_F(DocumentTest, NonConstGetItemReturnsCorrectItem)
{
    const std::string paragraphText = "Test paragraph";
    doc.InsertParagraph(paragraphText, std::nullopt);
    DocumentItem *item = doc.GetItem(0);
    ASSERT_NE(item, nullptr);
    IParagraph *paragraph = item->GetParagraph();
    ASSERT_NE(paragraph, nullptr);
    EXPECT_EQ(paragraph->GetText(), paragraphText);
}

TEST_F(DocumentTest, DeleteItemReducesItemCount)
{
    doc.InsertParagraph("Paragraph 1", std::nullopt);
    doc.InsertParagraph("Paragraph 2", std::nullopt);
    EXPECT_EQ(doc.GetItemsCount(), 2);
    doc.DeleteItem(0);
    EXPECT_EQ(doc.GetItemsCount(), 1);
}

TEST_F(DocumentTest, DeleteItemOutOfRangeThrows) { EXPECT_THROW(doc.DeleteItem(0), std::out_of_range); }

TEST_F(DocumentTest, SetDeletedThrowsIfNotImage)
{
    doc.InsertParagraph("Paragraph", std::nullopt);
    EXPECT_THROW(doc.SetDeleted(0, true), std::runtime_error);
}

TEST_F(DocumentTest, SetDeletedWorksForImage)
{
    doc.InsertImage("path/to/image.png", 800, 600, std::nullopt);
    EXPECT_NO_THROW(doc.SetDeleted(0, true));
    const IImage *image = doc.GetItem(0)->GetImage();
    ASSERT_NE(image, nullptr);
    EXPECT_TRUE(image->GetDeleted());
}

TEST_F(DocumentTest, SaveCallsExporterWithCorrectParameters)
{
    const std::string path = "output.doc";
    const testing::NiceMock<MockExporter> exporter;
    doc.InsertParagraph("Test paragraph", std::nullopt);

    EXPECT_CALL(exporter, Export(path, testing::_)).Times(1);

    doc.Save(path, exporter);
}
