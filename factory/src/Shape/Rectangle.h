#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(Color color, Point leftTop, Point rightBottom) :
        Shape(color),
        m_leftTop(leftTop),
        m_rightBottom(rightBottom){};

    void Draw(ICanvas &canvas) const override
    {
        canvas.SetColor(colorStringMap.at(GetColor()));
        canvas.DrawLine(m_leftTop, Point(m_rightBottom.x, m_leftTop.y));
        canvas.DrawLine(Point(m_rightBottom.x, m_leftTop.y), m_rightBottom);
        canvas.DrawLine(m_rightBottom, Point(m_leftTop.x, m_rightBottom.y));
        canvas.DrawLine(Point(m_leftTop.x, m_rightBottom.y), m_leftTop);
    };

    Point GetLeftTop() const { return m_leftTop; }

    Point GetRightBottom() const { return m_rightBottom; }

    static std::string GetType() { return "rectangle"; };

private:
    Point m_leftTop;
    Point m_rightBottom;
};

#endif // RECTANGLE_H
