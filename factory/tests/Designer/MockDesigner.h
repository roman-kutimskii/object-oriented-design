#ifndef MOCKDESIGNER_H
#define MOCKDESIGNER_H

#include <gmock/gmock.h>

#include "../../src/Designer/IDesigner.h"

class MockDesigner : public IDesigner
{
public:
    MOCK_METHOD(PictureDraft, CreateDraft, (std::istream & inputData), (override));
};

#endif // MOCKDESIGNER_H
