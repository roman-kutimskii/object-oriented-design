#include <gtest/gtest.h>

#include "../../src/Shape/Color.h"
#include "../../src/Shape/RegularPolygon.h"
#include "../Canvas/MockCanvas.h"

TEST(RegularPolygon, IsBeingCreated)
{
    RegularPolygon polygon(Color::Red, {0, 0}, 10, 5);

    EXPECT_EQ(polygon.GetColor(), Color::Red);
    EXPECT_EQ(polygon.GetCenter(), Point(0, 0));
    EXPECT_EQ(polygon.GetRadius(), 10);
    EXPECT_EQ(polygon.GetVertexCount(), 5);
}

TEST(RegularPolygon, ThrowsOnInvalidVertexCount)
{
    EXPECT_THROW(RegularPolygon(Color::Red, {0, 0}, 10, 2), std::invalid_argument);
}

TEST(RegularPolygon, IsBeingDrawn)
{
    MockCanvas canvas;
    RegularPolygon polygon(Color::Green, {0, 0}, 10, 3);

    EXPECT_CALL(canvas, SetColor(colorStringMap.at(Color::Green))).Times(1);

    const double angleIncrement = 2 * M_PI / 3;
    std::vector<Point> expectedVertices;
    for (int i = 0; i < 3; ++i)
    {
        double angle = i * angleIncrement;
        int x = static_cast<int>(0 + 10 * cos(angle));
        int y = static_cast<int>(0 + 10 * sin(angle));
        expectedVertices.push_back(Point{x, y});
    }

    for (int i = 0; i < 3; ++i)
    {
        const Point &from = expectedVertices[i];
        const Point &to = expectedVertices[(i + 1) % 3];
        EXPECT_CALL(canvas, DrawLine(from, to)).Times(1);
    }

    polygon.Draw(canvas);
}
