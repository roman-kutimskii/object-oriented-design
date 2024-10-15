#ifndef RUBBERDUCK_H
#define RUBBERDUCK_H

#include "Duck.h"
#include "Quack/QuackFunctions.h"

class RubberDuck final : public Duck
{
public:
	RubberDuck()
		: Duck(nullptr, QuackSqueak, nullptr){};

	void Display() const override
	{
		std::cout << "I'm a rubber duck!" << std::endl;
	};
};

#endif // RUBBERDUCK_H
