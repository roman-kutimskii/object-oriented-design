#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape
{
public:
    Triangle(Color color, Point point1, Point point2, Point point3) :
        Shape(color),
        m_point1(point1),
        m_point2(point2),
        m_point3(point3){};

    void Draw(ICanvas &canvas) const override
    {
        canvas.SetColor(colorStringMap.at(GetColor()));
        canvas.DrawLine(m_point1, m_point2);
        canvas.DrawLine(m_point2, m_point3);
        canvas.DrawLine(m_point3, m_point1);
    };

    Point GetPoint1() const { return m_point1; }

    Point GetPoint2() const { return m_point2; }

    Point GetPoint3() const { return m_point3; }

    static std::string GetType() { return "triangle"; };

private:
    Point m_point1;
    Point m_point2;
    Point m_point3;
};

#endif // TRIANGLE_H
