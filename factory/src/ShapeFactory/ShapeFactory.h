#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include <sstream>
#include "../Shape/Ellipse.h"
#include "../Shape/Rectangle.h"
#include "../Shape/RegularPolygon.h"
#include "../Shape/Triangle.h"
#include "IShapeFactory.h"

class ShapeFactory : public IShapeFactory
{
public:
    std::shared_ptr<Shape> CreateShape(std::string &description) override
    {
        std::stringstream iss(description);

        std::string shapeType, colorString;
        iss >> shapeType >> colorString;
        Color color = colorMap.at(colorString);

        if (shapeType == Triangle::GetType())
        {
            return CreateTriangle(color, iss);
        }
        else if (shapeType == Ellipse::GetType())
        {
            return CreateEllipse(color, iss);
        }
        else if (shapeType == Rectangle::GetType())
        {
            return CreateRectangle(color, iss);
        }
        else if (shapeType == RegularPolygon::GetType())
        {
            return CreateRegularPolygon(color, iss);
        }
    };

private:
    static std::unique_ptr<Ellipse> CreateEllipse(Color color, std::istringstream &iss)
    {
        std::string centerX;
        std::string centerY;
        std::string horizontalRadius;
        std::string verticalRadius;

        iss >> centerX >> centerY >> horizontalRadius >> verticalRadius;

        return std::make_unique<Ellipse>(
            color, Point(std::stoi(centerX), std::stoi(centerY)), std::stoi(horizontalRadius), std::stoi(verticalRadius)
        );
    };

    static std::unique_ptr<Rectangle> CreateRectangle(Color color, std::istringstream &iss)
    {
        std::string topLeftX;
        std::string topLeftY;
        std::string bottomRightX;
        std::string bottomRightY;

        iss >> topLeftX >> topLeftY >> bottomRightX >> bottomRightY;

        return std::make_unique<Rectangle>(
            color, Point(std::stoi(topLeftX), std::stoi(topLeftY)),
            Point(std::stoi(bottomRightX), std::stoi(bottomRightY))
        );
    };

    static std::unique_ptr<RegularPolygon> CreateRegularPolygon(Color color, std::istringstream &iss)
    {
        std::string centerX;
        std::string centerY;
        std::string radius;
        std::string vertexCount;

        iss >> centerX >> centerY >> radius >> vertexCount;

        return std::make_unique<RegularPolygon>(
            color, Point(std::stoi(centerX), std::stoi(centerY)), std::stoi(radius), std::stoi(vertexCount)
        );
    };

    static std::unique_ptr<Triangle> CreateTriangle(Color color, std::istringstream &iss)
    {
        std::string point1X;
        std::string point1Y;
        std::string point2X;
        std::string point2Y;
        std::string point3X;
        std::string point3Y;

        iss >> point1X >> point1Y >> point2X >> point2Y >> point3X;

        return std::make_unique<Triangle>(
            color, Point(std::stoi(point1X), std::stoi(point1Y)), Point(std::stoi(point2X), std::stoi(point2Y)),
            Point(std::stoi(point3X), std::stoi(point3Y))
        );
    };
};

#endif // SHAPEFACTORY_H
