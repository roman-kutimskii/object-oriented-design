#ifndef DESIGNER_H
#define DESIGNER_H

#include "../ShapeFactory/IShapeFactory.h"
#include "IDesigner.h"

class Designer : public IDesigner
{
public:
    Designer(IShapeFactory &shapeFactory) : m_shapesFactory(shapeFactory){};

    PictureDraft CreateDraft(std::istream &inputData) override
    {
        PictureDraft draft;
        std::string line;
        while (getline(inputData, line))
        {
            draft.AddShape(std::move(m_shapesFactory.CreateShape(line)));
        }
        return draft;
    };

private:
    IShapeFactory &m_shapesFactory;
};

#endif // DESIGNER_H
