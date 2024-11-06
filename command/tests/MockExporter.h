#ifndef MOCKEXPORTER_H
#define MOCKEXPORTER_H

#include <gmock/gmock-function-mocker.h>


#include "../src/IExporter.h"

class MockExporter : public IExporter
{
    MOCK_METHOD(
        void, Export, (const std::string &path, std::vector<std::unique_ptr<DocumentItem>> items), (const, override)
    );
};

#endif // MOCKEXPORTER_H
