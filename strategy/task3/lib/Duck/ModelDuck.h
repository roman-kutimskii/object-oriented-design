#ifndef MODELDUCK_H
#define MODELDUCK_H

#include "Duck.h"
#include "Quack/QuackFunctions.h"

class ModelDuck final : public Duck
{
public:
	ModelDuck()
		: Duck(nullptr, CreateQuackQuack(), nullptr){};

	void Display() const override
	{
		std::cout << "I'm a model duck!" << std::endl;
	};
};

#endif // MODELDUCK_H
