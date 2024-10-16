#ifndef CONSOLECANVAS_H
#define CONSOLECANVAS_H

#include <iostream>
#include <string>
#include "ICanvas.h"
#include "Point.h"

class ConsoleCanvas : public ICanvas
{
public:
    void SetColor(std::string color) override { std::cout << "Setting color to: " << color << std::endl; }

    void DrawLine(Point from, Point to) override
    {
        std::cout << "Drawing line from (" << from.x << ", " << from.y << ") to (" << to.x << ", " << to.y << ")"
                  << std::endl;
    }

    void DrawEllipse(Point center, int horizontalRadius, int verticalRadius) override
    {
        std::cout << "Drawing ellipse at center (" << center.x << ", " << center.y << ") with horizontal radius "
                  << horizontalRadius << " and vertical radius " << verticalRadius << std::endl;
    }
};


#endif // CONSOLECANVAS_H
