#ifndef DECOYDUCK_H
#define DECOYDUCK_H

#include "Duck.h"

class DecoyDuck final : public Duck
{
public:
	DecoyDuck()
		: Duck(nullptr, nullptr, nullptr){};

	void Display() const override
	{
		std::cout << "I'm a decoy duck!" << std::endl;
	}
};

#endif // DECOYDUCK_H
