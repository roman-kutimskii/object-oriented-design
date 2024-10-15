#ifndef MALLARDDUCK_H
#define MALLARDDUCK_H

#include "Dance/DanceWaltz.h"
#include "Duck.h"
#include "Fly/FlyWithWings.h"
#include "Quack/QuackBehavior.h"

class MallardDuck final : public Duck
{
public:
	MallardDuck()
		: Duck(std::make_unique<FlyWithWings>(),
			  std::make_unique<QuackBehavior>(),
			  std::make_unique<DanceWaltz>()){};

	void Display() const override
	{
		std::cout << "I'm a mallard duck!" << std::endl;
	};
};

#endif // MALLARDDUCK_H
