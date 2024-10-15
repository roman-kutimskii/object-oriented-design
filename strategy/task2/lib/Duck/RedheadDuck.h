#ifndef REDHEADDUCK_H
#define REDHEADDUCK_H

#include "Dance/DanceMinuet.h"
#include "Duck.h"
#include "Fly/FlyWithWingsAndCount.h"
#include "Quack/QuackBehavior.h"

class RedheadDuck final : public Duck
{
public:
	RedheadDuck()
		: Duck(std::make_unique<FlyWithWingsAndCount>(),
			  std::make_unique<QuackBehavior>(),
			  std::make_unique<DanceMinuet>()){};

	void Display() const override
	{
		std::cout << "I'm a redhead duck!" << std::endl;
	};
};

#endif // REDHEADDUCK_H
