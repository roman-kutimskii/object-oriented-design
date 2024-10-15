#ifndef DECOYDUCK_H
#define DECOYDUCK_H

#include "Dance/DanceNoWay.h"
#include "Duck.h"
#include "Fly/FlyNoWay.h"
#include "Quack/MuteQuackBehavior.h"

class DecoyDuck final : public Duck
{
public:
	DecoyDuck()
		: Duck(std::make_unique<FlyNoWay>(),
			  std::make_unique<MuteQuackBehavior>(),
			  std::make_unique<DanceNoWay>()){};

	void Display() const override
	{
		std::cout << "I'm a decoy duck!" << std::endl;
	};
};

#endif // DECOYDUCK_H
