#ifndef PICTUREDRAFT_H
#define PICTUREDRAFT_H

#include <memory>
#include <stdexcept>
#include <vector>

#include "Shape.h"

class PictureDraft
{
public:
    size_t GetShapeCount() const { return m_shapes.size(); }

    const Shape &GetShape(size_t index) const
    {
        if (index >= m_shapes.size())
        {
            throw std::out_of_range("Index out of range");
        }
        return *m_shapes[index];
    }

    void AddShape(std::unique_ptr<Shape> shape) { m_shapes.push_back(std::move(shape)); }

private:
    std::vector<std::unique_ptr<Shape>> m_shapes;
};

#endif // PICTUREDRAFT_H
