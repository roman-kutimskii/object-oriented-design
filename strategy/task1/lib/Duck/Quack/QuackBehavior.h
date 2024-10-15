#ifndef QUACKBEHAVIOR_H
#define QUACKBEHAVIOR_H

#include <iostream>

#include "IQuackBehavior.h"

class QuackBehavior final : public IQuackBehavior
{
public:
	void Quack() override
	{
		std::cout << "Quack-quack!" << std::endl;
	}
};

#endif // QUACKBEHAVIOR_H
