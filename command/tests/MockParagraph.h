#ifndef MOCKPARAGRAPH_H
#define MOCKPARAGRAPH_H

#include <gmock/gmock.h>

#include "../src/IParagraph.h"

class MockParagraph final : public IParagraph
{
public:
    MOCK_METHOD(const std::string &, GetText, (), (const, override));
    MOCK_METHOD(void, SetText, (const std::string &text), (override));
};

#endif // MOCKPARAGRAPH_H
