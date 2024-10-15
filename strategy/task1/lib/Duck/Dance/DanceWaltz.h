#ifndef DANCEWALTZ_H
#define DANCEWALTZ_H

#include <iostream>

#include "IDanceBehavior.h"

class DanceWaltz final : public IDanceBehavior
{
public:
	void Dance() override
	{
		std::cout << "I'm dancing a waltz!" << std::endl;
	};
};

#endif // DANCEWALTZ_H
