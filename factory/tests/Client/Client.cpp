#include <gtest/gtest.h>

#include "../../src/Client/Client.h"
#include "../Canvas/MockCanvas.h"
#include "../Designer/MockDesigner.h"
#include "../Painter/MockPainter.h"

TEST(ClientTest, HandleCommand)
{
    testing::NiceMock<MockDesigner> mockDesigner;
    testing::NiceMock<MockPainter> mockPainter;
    testing::NiceMock<MockCanvas> mockCanvas;

    PictureDraft draft;

    EXPECT_CALL(mockDesigner, CreateDraft(testing::_)).Times(1);

    EXPECT_CALL(mockPainter, DrawPicture(testing::_, testing::_)).Times(1);

    Client client(mockDesigner);

    std::istringstream inputData("shape1\nshape2\nshape3\n");

    client.HandleCommand(inputData, mockCanvas, mockPainter);
}
