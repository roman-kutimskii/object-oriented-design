#ifndef MOCKIMAGE_H
#define MOCKIMAGE_H

#include <gmock/gmock.h>

#include "../src/document/IImage.h"

class MockImage : public IImage
{
public:
    MOCK_METHOD(const std::string &, GetPath, (), (const, override));
    MOCK_METHOD(int, GetWidth, (), (const, override));
    MOCK_METHOD(int, GetHeight, (), (const, override));
    MOCK_METHOD(bool, GetDeleted, (), (const, override));
    MOCK_METHOD(void, Resize, (int width, int height), (override));
    MOCK_METHOD(void, SetDeleted, (bool value), (override));
};

#endif // MOCKIMAGE_H
