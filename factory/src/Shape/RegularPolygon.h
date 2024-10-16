#ifndef REGULARPOLYGON_H
#define REGULARPOLYGON_H

#include <cmath>
#include <stdexcept>
#include <vector>

#include "Shape.h"

class RegularPolygon : public Shape
{
public:
    RegularPolygon(Color color, Point center, int radius, int vertexCount) :
        Shape(color),
        m_center(center),
        m_radius(radius)
    {
        if (vertexCount < 3)
        {
            throw std::invalid_argument("A polygon must have at least 3 vertices.");
        }
        m_vertexCount = vertexCount;
    };

    void Draw(ICanvas &canvas) const override
    {
        canvas.SetColor(colorStringMap.at(GetColor()));
        const double angleIncrement = 2 * M_PI / m_vertexCount;
        std::vector<Point> vertices;

        for (int i = 0; i < m_vertexCount; ++i)
        {
            double angle = i * angleIncrement;
            int x = static_cast<int>(m_center.x + m_radius * cos(angle));
            int y = static_cast<int>(m_center.y + m_radius * sin(angle));
            vertices.push_back(Point{x, y});
        }

        for (int i = 0; i < m_vertexCount; ++i)
        {
            const Point &from = vertices[i];
            const Point &to = vertices[(i + 1) % m_vertexCount];
            canvas.DrawLine(from, to);
        }
    };

    Point GetCenter() const { return m_center; }

    int GetRadius() const { return m_radius; }

    int GetVertexCount() const { return m_vertexCount; }

    static std::string GetType() { return "regpol"; };

private:
    Point m_center;
    int m_radius;
    int m_vertexCount;
};

#endif // REGULARPOLYGON_H
