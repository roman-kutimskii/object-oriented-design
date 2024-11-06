#ifndef IMAGE_H
#define IMAGE_H

#include <utility>

#include "IImage.h"

class Image final : public IImage
{
public:
    Image(std::string path, const int width, const int height) :
        m_path(std::move(path)),
        m_width(width),
        m_height(height)
    {
    }

    [[nodiscard]] const std::string &GetPath() const override { return m_path; }

    [[nodiscard]] int GetWidth() const override { return m_width; }

    [[nodiscard]] int GetHeight() const override { return m_height; }

    [[nodiscard]] bool GetDeleted() const override { return m_deleted; }

    void Resize(const int width, const int height) override
    {
        m_width = width;
        m_height = height;
    }

    void SetDeleted(const bool value) override { m_deleted = value; }

private:
    std::string m_path;
    int m_width;
    int m_height;
    bool m_deleted = false;
};

#endif // IMAGE_H
