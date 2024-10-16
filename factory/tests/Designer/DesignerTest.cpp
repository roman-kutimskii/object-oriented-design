#include <gtest/gtest.h>

#include "../../src/Designer/Designer.h"
#include "../Shape/MockShape.h"
#include "../ShapeFactory/MockShapeFactory.h"

TEST(DesignerTest, CreateDraft)
{
    MockShapeFactory mockFactory;

    EXPECT_CALL(mockFactory, CreateShape("shape1")).WillOnce(testing::Return(std::make_unique<MockShape>(Color::Red)));
    EXPECT_CALL(mockFactory, CreateShape("shape2")).WillOnce(testing::Return(std::make_unique<MockShape>(Color::Green)));
    EXPECT_CALL(mockFactory, CreateShape("shape3")).WillOnce(testing::Return(std::make_unique<MockShape>(Color::Blue)));

    Designer designer(mockFactory);

    std::istringstream inputData("shape1\nshape2\nshape3\n");

    PictureDraft draft = designer.CreateDraft(inputData);

    EXPECT_EQ(draft.GetShapeCount(), 3);

    EXPECT_EQ(draft.GetShape(0).GetColor(), Color::Red);
    EXPECT_EQ(draft.GetShape(1).GetColor(), Color::Green);
    EXPECT_EQ(draft.GetShape(2).GetColor(), Color::Blue);
}
