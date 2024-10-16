#include <gtest/gtest.h>

#include "../../src/Shape/Color.h"
#include "../../src/Shape/Ellipse.h"
#include "../Canvas/MockCanvas.h"

TEST(Ellipse, IsBeingCreated)
{
    Ellipse ellipse(Color::Black, {0, 0}, 10, 10);

    EXPECT_EQ(ellipse.GetColor(), Color::Black);
    EXPECT_EQ(ellipse.GetCenter(), Point(0, 0));
    EXPECT_EQ(ellipse.GetHorizontalRadius(), 10);
    EXPECT_EQ(ellipse.GetVerticalRadius(), 10);
}

TEST(Ellipse, IsBeingDrawn)
{
    MockCanvas canvas;
    Ellipse ellipse(Color::Black, {0, 0}, 10, 10);

    EXPECT_CALL(canvas, SetColor(colorStringMap.at(Color::Black))).Times(1);
    EXPECT_CALL(canvas, DrawEllipse(Point(0, 0), 10, 10)).Times(1);

    ellipse.Draw(canvas);
}
