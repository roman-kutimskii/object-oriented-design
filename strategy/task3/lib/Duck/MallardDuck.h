#ifndef MALLARDDUCK_H
#define MALLARDDUCK_H

#include "Dance/DanceFunctions.h"
#include "Duck.h"
#include "Fly/FlyFunctions.h"
#include "Quack/QuackFunctions.h"

class MallardDuck final : public Duck
{
public:
	// TODO: Придумать, чтобы ошибка не оставалась незамеченной.

	MallardDuck()
		: Duck(CreateFlyWithWings, QuackQuack, DanceWaltz){};

	void Display() const override
	{
		std::cout << "I'm a mallard duck!" << std::endl;
	};
};

#endif // MALLARDDUCK_H
