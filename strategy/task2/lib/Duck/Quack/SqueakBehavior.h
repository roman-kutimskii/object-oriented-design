#ifndef SQUEAKBEHAVIOR_H
#define SQUEAKBEHAVIOR_H

#include <iostream>

#include "IQuackBehavior.h"

class SqueakBehavior final : public IQuackBehavior
{
public:
	void Quack() override
	{
		std::cout << "Squeak!" << std::endl;
	}
};

#endif // SQUEAKBEHAVIOR_H
