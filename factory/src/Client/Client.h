#ifndef CLIENT_H
#define CLIENT_H
#include "../Designer/IDesigner.h"
#include "../Painter/IPainter.h"

class Client
{
public:
    Client(IDesigner &designer) : m_designer(designer){};

    void HandleCommand(std::istream &input, ICanvas &canvas, const IPainter &painter)
    {
        PictureDraft draft = m_designer.CreateDraft(input);
        painter.DrawPicture(draft, canvas);
    };

private:
    IDesigner &m_designer;
};

#endif // CLIENT_H
