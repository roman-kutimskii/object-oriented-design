#ifndef MOCKEXPORTER_H
#define MOCKEXPORTER_H

#include <gmock/gmock.h>

#include "../src/IExporter.h"

class MockExporter : public IExporter
{
public:
    MOCK_METHOD(
        void, Export, (const std::string &path, const std::vector<std::unique_ptr<DocumentItem>> &items),
        (const, override)
    );
};

#endif // MOCKEXPORTER_H
