#ifndef QUACKFUNCTIONS_H
#define QUACKFUNCTIONS_H

#include <iostream>

inline QuackBehavior CreateQuackQuack()
{
	return [] {
		std::cout << "Quack-quack!" << std::endl;
	};
}

inline QuackBehavior CreateQuackSqueak()
{
	return [] {
		std::cout << "Squeak!" << std::endl;
	};
}

#endif // QUACKFUNCTIONS_H
