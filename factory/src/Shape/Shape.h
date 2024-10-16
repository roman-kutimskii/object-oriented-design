#ifndef SHAPE_H
#define SHAPE_H

#include "../Canvas/ICanvas.h"
#include "Color.h"

class Shape
{
public:
    Shape(const Color color) : m_color(color) {}

    virtual void Draw(ICanvas &canvas) const = 0;

    Color GetColor() const { return m_color; }

    virtual ~Shape() = default;
private:
    Color m_color;
};

#endif // SHAPE_H
