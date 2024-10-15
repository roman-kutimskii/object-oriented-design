#ifndef RUBBERDUCK_H
#define RUBBERDUCK_H

#include "Dance/DanceNoWay.h"
#include "Duck.h"
#include "Fly/FlyNoWay.h"
#include "Quack/SqueakBehavior.h"

class RubberDuck final : public Duck
{
public:
	RubberDuck()
		: Duck(
			  std::make_unique<FlyNoWay>(),
			  std::make_unique<SqueakBehavior>(),
			  std::make_unique<DanceNoWay>()){};

	void Display() const override
	{
		std::cout << "I'm a rubber duck!" << std::endl;
	};
};

#endif // RUBBERDUCK_H
