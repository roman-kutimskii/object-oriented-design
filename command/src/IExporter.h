#ifndef IEXPORTER_H
#define IEXPORTER_H

#include <memory>
#include <string>
#include <vector>

#include "DocumentItem.h"

class IExporter
{
public:
    virtual ~IExporter() = default;
    virtual void Export(const std::string &path, std::vector<std::unique_ptr<DocumentItem>> items) const = 0;
};

#endif // IEXPORTER_H
