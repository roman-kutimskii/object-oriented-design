#ifndef DANCEMINUET_H
#define DANCEMINUET_H

#include <iostream>

#include "IDanceBehavior.h"

class DanceMinuet final : public IDanceBehavior
{
public:
	void Dance() override
	{
		std::cout << "I'm dancing a minuet!" << std::endl;
	};
};

#endif // DANCEMINUET_H
