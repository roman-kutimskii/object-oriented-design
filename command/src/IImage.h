#ifndef IIMAGE_H
#define IIMAGE_H

#include <string>

class IImage
{
public:
    virtual ~IImage() = default;
    [[nodiscard]] virtual std::string GetPath() const = 0;
    [[nodiscard]] virtual int GetWidth() const = 0;
    [[nodiscard]] virtual int GetHeight() const = 0;
    [[nodiscard]] virtual bool GetDeleted() const = 0;
    virtual void Resize(int width, int height) = 0;
    virtual void SetDeleted(bool deleted) = 0;
};

#endif // IIMAGE_H
