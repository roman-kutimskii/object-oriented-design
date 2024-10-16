#ifndef MOCKCANVAS_H
#define MOCKCANVAS_H

#include <gmock/gmock.h>

#include "../../src/Canvas/ICanvas.h"

class MockCanvas : public ICanvas
{
public:
    MOCK_METHOD(void, SetColor, (std::string color), (override));

    MOCK_METHOD(void, DrawLine, (Point from, Point to), (override));

    MOCK_METHOD(void, DrawEllipse, (Point leftTop, int width, int height), (override));
};

#endif // MOCKCANVAS_H
