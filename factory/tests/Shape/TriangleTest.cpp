#include <gtest/gtest.h>

#include "../../src/Shape/Color.h"
#include "../../src/Shape/Triangle.h"
#include "../Canvas/MockCanvas.h"

TEST(Triangle, IsBeingCreated)
{
    Triangle ellipse(Color::Black, {5, 0}, {10, 10}, {0, 10});

    EXPECT_EQ(ellipse.GetColor(), Color::Black);
    EXPECT_EQ(ellipse.GetPoint1(), Point(5, 0));
    EXPECT_EQ(ellipse.GetPoint2(), Point(10, 10));
    EXPECT_EQ(ellipse.GetPoint3(), Point(0, 10));
}

TEST(Triangle, IsBeingDrawn)
{
    MockCanvas canvas;
    Triangle ellipse(Color::Black, {5, 0}, {10, 10}, {0, 10});

    EXPECT_CALL(canvas, SetColor(colorStringMap.at(Color::Black))).Times(1);
    EXPECT_CALL(canvas, DrawLine(Point(5, 0), Point(10, 10))).Times(1);
    EXPECT_CALL(canvas, DrawLine(Point(10, 10), Point(0, 10))).Times(1);
    EXPECT_CALL(canvas, DrawLine(Point(0, 10), Point(5, 0))).Times(1);

    ellipse.Draw(canvas);
}
