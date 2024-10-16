#ifndef MOCKSHAPE_H
#define MOCKSHAPE_H

#include <gmock/gmock.h>

#include "../../src/Shape/Shape.h"

class MockShape : public Shape
{
public:
    MockShape(Color color) : Shape(color) {}

    MOCK_METHOD(void, Draw, (ICanvas & canvas), (const, override));
};

#endif // MOCKSHAPE_H
