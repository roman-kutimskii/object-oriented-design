#ifndef MUTEQUACKBEHAVIOR_H
#define MUTEQUACKBEHAVIOR_H

#include "IQuackBehavior.h"

class MuteQuackBehavior final : public IQuackBehavior
{
public:
	void Quack() override{};
};

#endif // MUTEQUACKBEHAVIOR_H
