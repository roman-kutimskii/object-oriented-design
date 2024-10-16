#ifndef MOCKSHAPEFACTORY_H
#define MOCKSHAPEFACTORY_H

#include <gmock/gmock.h>

#include "../../src/Shape/Shape.h"
#include "../../src/ShapeFactory/IShapeFactory.h"

class MockShapeFactory : public IShapeFactory
{
public:
    MOCK_METHOD(std::unique_ptr<Shape>, CreateShape, (const std::string &description), (const, override));
};

#endif // MOCKSHAPEFACTORY_H
