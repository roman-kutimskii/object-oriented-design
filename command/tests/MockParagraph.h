#ifndef MOCKPARAGRAPH_H
#define MOCKPARAGRAPH_H

#include <gmock/gmock.h>

#include "../src/document/IParagraph.h"

class MockParagraph : public IParagraph
{
public:
    MOCK_METHOD(const std::string &, GetText, (), (const, override));
    MOCK_METHOD(void, SetText, (const std::string &text), (override));
};

#endif // MOCKPARAGRAPH_H
