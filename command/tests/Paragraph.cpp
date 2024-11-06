#include <gtest/gtest.h>

#include "../src/Paragraph.h"

TEST(ParagraphTest, ConstructorAndGetText)
{
    const Paragraph paragraph("Initial text");
    EXPECT_EQ(paragraph.GetText(), "Initial text");
}

TEST(ParagraphTest, SetText)
{
    Paragraph paragraph("Initial text");
    paragraph.SetText("Updated text");
    EXPECT_EQ(paragraph.GetText(), "Updated text");
}

TEST(ParagraphTest, SetEmptyText)
{
    Paragraph paragraph("Initial text");
    paragraph.SetText("");
    EXPECT_EQ(paragraph.GetText(), "");
}
