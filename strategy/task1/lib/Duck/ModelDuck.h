#ifndef MODELDUCK_H
#define MODELDUCK_H

#include "Dance/DanceNoWay.h"
#include "Duck.h"
#include "Fly/FlyNoWay.h"
#include "Quack/QuackBehavior.h"

class ModelDuck final : public Duck
{
public:
	ModelDuck()
		: Duck(std::make_unique<FlyNoWay>(),
			  std::make_unique<QuackBehavior>(),
			  std::make_unique<DanceNoWay>()){};

	void Display() const override
	{
		std::cout << "I'm a model duck!" << std::endl;
	};
};

#endif // MODELDUCK_H
