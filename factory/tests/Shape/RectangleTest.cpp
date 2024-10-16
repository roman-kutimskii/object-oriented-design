#include <gtest/gtest.h>

#include "../../src/Shape/Color.h"
#include "../../src/Shape/Rectangle.h"
#include "../Canvas/MockCanvas.h"

TEST(Rectangle, IsBeingCreated)
{
    Rectangle rectangle(Color::Black, {5, 5}, {10, 10});

    EXPECT_EQ(rectangle.GetColor(), Color::Black);
    EXPECT_EQ(rectangle.GetLeftTop(), Point(5, 5));
    EXPECT_EQ(rectangle.GetRightBottom(), Point(10, 10));
}

TEST(Rectangle, IsBeingDrawn)
{
    MockCanvas canvas;
    Rectangle rectangle(Color::Black, {5, 5}, {10, 10});

    EXPECT_CALL(canvas, SetColor(colorStringMap.at(Color::Black))).Times(1);
    EXPECT_CALL(canvas, DrawLine(Point(5, 5), Point(10, 5))).Times(1);
    EXPECT_CALL(canvas, DrawLine(Point(10, 5), Point(10, 10))).Times(1);
    EXPECT_CALL(canvas, DrawLine(Point(10, 10), Point(5, 10))).Times(1);
    EXPECT_CALL(canvas, DrawLine(Point(5, 10), Point(5, 5))).Times(1);

    rectangle.Draw(canvas);
}
