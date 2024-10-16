#ifndef ICANVAS_H
#define ICANVAS_H

#include <string>
#include "Point.h"

class ICanvas
{
public:
    virtual void SetColor(std::string color) = 0;

    virtual void DrawLine(Point from, Point to) = 0;

    virtual void DrawEllipse(Point center, int horizontalRadius, int verticalRadius) = 0;

    virtual ~ICanvas() = default;
};

#endif // ICANVAS_H
