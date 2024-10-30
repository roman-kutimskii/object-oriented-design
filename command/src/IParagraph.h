#ifndef IPARAGRAPH_H
#define IPARAGRAPH_H
#include <string>

class IParagraph
{
public:
    virtual ~IParagraph() = default;
    [[nodiscard]] virtual std::string GetText() const = 0;
    virtual void SetText() = 0;
};

#endif // IPARAGRAPH_H
