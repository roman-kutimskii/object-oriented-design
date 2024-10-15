#ifndef MALLARDDUCK_H
#define MALLARDDUCK_H

#include "Dance/DanceFunctions.h"
#include "Duck.h"
#include "Fly/FlyFunctions.h"
#include "Quack/QuackFunctions.h"

class MallardDuck final : public Duck
{
public:
	MallardDuck()
		: Duck(CreateFlyWithWings(), CreateQuackQuack(), CreateDanceWaltz()){};

	void Display() const override
	{
		std::cout << "I'm a mallard duck!" << std::endl;
	};
};

#endif // MALLARDDUCK_H
