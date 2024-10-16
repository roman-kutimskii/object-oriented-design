#ifndef IPAINTER_H
#define IPAINTER_H

#include "../Shape/PictureDraft.h"

class IPainter
{
public:
    virtual void DrawPicture(const PictureDraft &draft, ICanvas &canvas) const = 0;

    virtual ~IPainter() = default;
};

#endif // IPAINTER_H
