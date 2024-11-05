#ifndef MOCKIMAGE_H
#define MOCKIMAGE_H

#include <gmock/gmock.h>

#include "../src/IImage.h"

class MockImage final : public IImage
{
public:
    MOCK_METHOD(std::string, GetPath, (), (const, override));
    MOCK_METHOD(int, GetWidth, (), (const, override));
    MOCK_METHOD(int, GetHeight, (), (const, override));
    MOCK_METHOD(bool, GetDeleted, (), (const, override));
    MOCK_METHOD(void, Resize, (int width, int height), (override));
    MOCK_METHOD(void, SetDeleted, (bool deleted), (override));
};

#endif // MOCKIMAGE_H
