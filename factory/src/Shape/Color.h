#ifndef COLOR_H
#define COLOR_H

enum class Color
{
    Red,
    Green,
    Blue,
    Pink,
    Yellow,
    Black
};

const std::map<std::string, Color> colorMap = {
    {"red", Color::Red},   {"green", Color::Green},   {"blue", Color::Blue},
    {"pink", Color::Pink}, {"yellow", Color::Yellow}, {"black", Color::Black},
};

const std::map<Color, std::string> colorStringMap
    = {{Color::Red, "red"},   {Color::Green, "green"},   {Color::Blue, "blue"},
       {Color::Pink, "pink"}, {Color::Yellow, "yellow"}, {Color::Black, "black"}};

#endif // COLOR_H
