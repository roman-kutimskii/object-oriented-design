#ifndef FLYFUNCTIONS_H
#define FLYFUNCTIONS_H

#include "../Duck.h"

inline Behavior CreateFlyWithWings()
{
	int flyCount = 0;
	return [flyCount]() mutable {
		++flyCount;
		std::cout << "I'm flying with wings!" << std::endl
				  << "I've done " << flyCount << " flight" << (flyCount > 1 ? "s" : "") << "." << std::endl;
	};
}

#endif // FLYFUNCTIONS_H
