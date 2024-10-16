#include <gtest/gtest.h>

#include "../../src/Shape/PictureDraft.h"
#include "MockShape.h"


TEST(PictureDraftTest, InitialState)
{
    PictureDraft draft;
    EXPECT_EQ(draft.GetShapeCount(), 0);
}

TEST(PictureDraftTest, AddShape)
{
    PictureDraft draft;
    draft.AddShape(std::make_unique<MockShape>(Color::Black));
    EXPECT_EQ(draft.GetShapeCount(), 1);
}

TEST(PictureDraftTest, GetShape)
{
    PictureDraft draft;
    auto shape = std::make_unique<MockShape>(Color::Black);
    auto shapePtr = shape.get();
    draft.AddShape(std::move(shape));

    const Shape &retrievedShape = draft.GetShape(0);
    EXPECT_EQ(&retrievedShape, shapePtr);
}

TEST(PictureDraftTest, GetShapeOutOfRange)
{
    PictureDraft draft;
    EXPECT_THROW(draft.GetShape(0), std::out_of_range);
}

TEST(PictureDraftTest, AddMultipleShapes)
{
    PictureDraft draft;
    draft.AddShape(std::make_unique<MockShape>(Color::Black));
    draft.AddShape(std::make_unique<MockShape>(Color::Black));
    draft.AddShape(std::make_unique<MockShape>(Color::Black));
    EXPECT_EQ(draft.GetShapeCount(), 3);
}

TEST(PictureDraftTest, VerifyShapes)
{
    PictureDraft draft;
    auto shape1 = std::make_unique<MockShape>(Color::Black);
    auto shape2 = std::make_unique<MockShape>(Color::Black);
    auto shape3 = std::make_unique<MockShape>(Color::Black);

    auto shapePtr1 = shape1.get();
    auto shapePtr2 = shape2.get();
    auto shapePtr3 = shape3.get();

    draft.AddShape(std::move(shape1));
    draft.AddShape(std::move(shape2));
    draft.AddShape(std::move(shape3));

    EXPECT_EQ(&draft.GetShape(0), shapePtr1);
    EXPECT_EQ(&draft.GetShape(1), shapePtr2);
    EXPECT_EQ(&draft.GetShape(2), shapePtr3);
}
