#include <gtest/gtest.h>

#include "../../src/ShapeFactory/ShapeFactory.h"

TEST(ShapeFactoryTest, CreateTriangle)
{
    ShapeFactory factory;
    std::string description = "triangle red 0 0 1 0 0 1";
    std::unique_ptr<Shape> shape = factory.CreateShape(description);

    ASSERT_NE(shape, nullptr);
}

TEST(ShapeFactoryTest, CreateEllipse)
{
    ShapeFactory factory;
    std::string description = "ellipse green 0 0 5 3";
    std::unique_ptr<Shape> shape = factory.CreateShape(description);
    ASSERT_NE(shape, nullptr);
}

TEST(ShapeFactoryTest, CreateRectangle)
{
    ShapeFactory factory;
    std::string description = "rectangle blue 0 0 3 4";
    std::unique_ptr<Shape> shape = factory.CreateShape(description);
    ASSERT_NE(shape, nullptr);
}

TEST(ShapeFactoryTest, CreateRegularPolygon)
{
    ShapeFactory factory;
    std::string description = "regpol red 0 0 5 6";
    std::unique_ptr<Shape> shape = factory.CreateShape(description);
    ASSERT_NE(shape, nullptr);
}

TEST(ShapeFactoryTest, InvalidShape) {
    ShapeFactory factory;
    std::string description = "unknown_shape red 0 0 1 1";
    EXPECT_THROW(factory.CreateShape(description), std::invalid_argument);
}
