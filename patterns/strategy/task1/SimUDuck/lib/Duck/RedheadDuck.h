#ifndef REDHEADDUCK_H
#define REDHEADDUCK_H

#include "Duck.h"
#include "Fly/FlyWithWings.h"
#include "Quack/QuackBehavior.h"

class RedheadDuck final : public Duck {
public:
    RedheadDuck() : Duck(std::make_unique<FlyWithWings>(), std::make_unique<QuackBehavior>()) {
    };

    void Display() const override {
        std::cout << "I'm a redhead duck!" << std::endl;
    };
};

#endif //REDHEADDUCK_H
