#ifndef REDHEADDUCK_H
#define REDHEADDUCK_H

#include "Duck.h"
#include "Dance/DanceFunctions.h"
#include "Fly/FlyFunctions.h"
#include "Quack/QuackFunctions.h"

class RedheadDuck final : public Duck
{
public:
    RedheadDuck() : Duck(CreateFlyWithWings, QuackQuack, DanceMinuet)
    {
    };

    void Display() const override
    {
        std::cout << "I'm a redhead duck!" << std::endl;
    };
};

#endif //REDHEADDUCK_H
