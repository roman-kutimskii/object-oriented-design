#ifndef MOCKPAINTER_H
#define MOCKPAINTER_H

#include <gmock/gmock.h>

#include "../../src/Painter/IPainter.h"

class MockPainter : public IPainter
{
public:
    MOCK_METHOD(void, DrawPicture, (const PictureDraft &draft, ICanvas &canvas), (const, override));
};

#endif // MOCKPAINTER_H
