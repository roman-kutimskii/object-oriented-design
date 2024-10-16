#include <gtest/gtest.h>

#include "../Canvas/MockCanvas.h"
#include "../Shape/MockShape.h"
#include "../../src/Shape/PictureDraft.h"
#include "../../src/Painter/Painter.h"

TEST(PainterTest, DrawPictureCallsDrawOnEachShape) {
    MockCanvas canvas;
    PictureDraft draft;
    auto shape1 = std::make_unique<MockShape>(Color::Red);
    auto shape2 = std::make_unique<MockShape>(Color::Green);

    MockShape* shapePtr1 = shape1.get();
    MockShape* shapePtr2 = shape2.get();

    draft.AddShape(std::move(shape1));
    draft.AddShape(std::move(shape2));

    Painter painter;

    {
        testing::InSequence seq;
        EXPECT_CALL(*shapePtr1, Draw(::testing::Ref(canvas))).Times(1);
        EXPECT_CALL(*shapePtr2, Draw(::testing::Ref(canvas))).Times(1);
    }

    painter.DrawPicture(draft, canvas);
}