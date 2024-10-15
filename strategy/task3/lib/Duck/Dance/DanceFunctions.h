#ifndef DANCEFUNCTIONS_H
#define DANCEFUNCTIONS_H

#include "../Duck.h"

inline DanceBehavior CreateDanceMinuet()
{
	return [] {
		std::cout << "I'm dancing a minuet!" << std::endl;
	};
}

inline DanceBehavior CreateDanceWaltz()
{
	return [] {
		std::cout << "I'm dancing a waltz!" << std::endl;
	};
}

#endif // DANCEFUNCTIONS_H
