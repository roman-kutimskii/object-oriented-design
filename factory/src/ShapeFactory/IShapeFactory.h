#ifndef ISHAPEFACTORY_H
#define ISHAPEFACTORY_H

#include <memory>

#include "../Shape/Shape.h"

class IShapeFactory
{
public:
    virtual std::unique_ptr<Shape> CreateShape(const std::string &description) const = 0;

    virtual ~IShapeFactory() = default;
};

#endif // ISHAPEFACTORY_H
