#include <iostream>

#include "Canvas/ConsoleCanvas.h"
#include "Client/Client.h"
#include "Designer/Designer.h"
#include "Painter/Painter.h"
#include "ShapeFactory/ShapeFactory.h"

int main()
{
    Painter painter;
    ConsoleCanvas canvas;
    ShapeFactory shapeFactory;
    Designer designer(shapeFactory);

    Client client(designer);

    client.HandleCommand(std::cin, canvas, painter);

    return 0;
}
