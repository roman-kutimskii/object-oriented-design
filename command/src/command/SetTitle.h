#ifndef SETTITLE_H
#define SETTITLE_H

#include "DocumentCommand.h"

class SetTitle : public DocumentCommand
{
public:
    SetTitle(std::shared_ptr<IDocument> document, const std::string &title) :
        DocumentCommand(std::move(document)),
        m_title(title)
    {
    }

    void Execute() override
    {
        m_prevTitle = m_document->GetTitle();
        m_document->SetTitle(m_title);
    }

    void Unexecute() override { m_document->SetTitle(m_prevTitle); }

private:
    const std::string &m_title;
    std::string m_prevTitle;
};

#endif // SETTITLE_H
