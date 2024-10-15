#ifndef FLYWITHWINGS_H
#define FLYWITHWINGS_H

#include <iostream>

#include "IFlyBehavior.h"

class FlyWithWingsAndCount final : public IFlyBehavior
{
public:
	void Fly() override
	{
		++m_flyCount;
		std::cout << "I'm flying with wings!" << std::endl
				  << "I've done " << m_flyCount << " flight" << (m_flyCount > 1 ? "s" : "") << "." << std::endl;
	};

private:
	int m_flyCount = 0;
};

#endif // FLYWITHWINGS_H
