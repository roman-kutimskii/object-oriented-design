#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Shape.h"

class Ellipse : public Shape
{
public:
    Ellipse(Color color, Point center, int horizontalRadius, int verticalRadius) :
        Shape(color),
        m_center(center),
        m_horizontalRadius(horizontalRadius),
        m_verticalRadius(verticalRadius){};


    void Draw(ICanvas &canvas) const override
    {
        canvas.SetColor(colorStringMap.at(GetColor()));
        canvas.DrawEllipse(m_center, m_horizontalRadius, m_verticalRadius);
    };

    Point GetCenter() const { return m_center; };

    int GetHorizontalRadius() const { return m_horizontalRadius; };

    int GetVerticalRadius() const { return m_verticalRadius; };

    static std::string GetType() { return "ellipse"; };

private:
    Point m_center;
    int m_horizontalRadius;
    int m_verticalRadius;
};

#endif // ELLIPSE_H
