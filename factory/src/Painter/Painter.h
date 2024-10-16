#ifndef PAINTER_H
#define PAINTER_H

#include "IPainter.h"

class Painter : public IPainter
{
public:
    void DrawPicture(const PictureDraft &draft, ICanvas &canvas) const override
    {
        const auto shapesCount = draft.GetShapeCount();
        for (int i = 0; i < shapesCount; ++i)
        {
            const auto &shape = draft.GetShape(i);
            shape.Draw(canvas);
        }
    };
};

#endif // PAINTER_H
