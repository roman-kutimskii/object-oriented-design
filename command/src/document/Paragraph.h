#ifndef PARAGRAPH_H
#define PARAGRAPH_H

#include <utility>

#include "IParagraph.h"

class Paragraph final : public IParagraph
{
public:
    explicit Paragraph(std::string text) : m_text(std::move(text)) {}

    [[nodiscard]] const std::string &GetText() const override { return m_text; }

    void SetText(const std::string &text) override { m_text = text; }

private:
    std::string m_text;
};

#endif // PARAGRAPH_H
