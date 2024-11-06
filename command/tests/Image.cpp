#include <gtest/gtest.h>

#include "../src/Image.h"

TEST(ImageTest, ConstructorAndGetters)
{
    const Image image("path/to/image.png", 640, 480);
    EXPECT_EQ(image.GetPath(), "path/to/image.png");
    EXPECT_EQ(image.GetWidth(), 640);
    EXPECT_EQ(image.GetHeight(), 480);
    EXPECT_FALSE(image.GetDeleted());
}

TEST(ImageTest, Resize)
{
    Image image("path/to/image.png", 640, 480);
    image.Resize(800, 600);
    EXPECT_EQ(image.GetWidth(), 800);
    EXPECT_EQ(image.GetHeight(), 600);
}

TEST(ImageTest, SetAndGetDeleted)
{
    Image image("path/to/image.png", 640, 480);
    image.SetDeleted(true);
    EXPECT_TRUE(image.GetDeleted());
    image.SetDeleted(false);
    EXPECT_FALSE(image.GetDeleted());
}
