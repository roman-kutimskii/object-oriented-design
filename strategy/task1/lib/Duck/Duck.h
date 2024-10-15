#ifndef DUCK_H
#define DUCK_H

#include <cassert>
#include <iostream>
#include <memory>

#include "Dance/IDanceBehavior.h"
#include "Fly/IFlyBehavior.h"
#include "Quack/IQuackBehavior.h"

// TODO: Показать на диаграмме, кто использует классы конкретных стратегий

class Duck
{
public:
	Duck(std::unique_ptr<IFlyBehavior>&& flyBehavior,
		std::unique_ptr<IQuackBehavior>&& quackBehavior,
		std::unique_ptr<IDanceBehavior>&& danceBehavior)
		: m_quackBehavior(std::move(quackBehavior))
		, m_danceBehavior(std::move(danceBehavior))
	{
		assert(m_quackBehavior);
		assert(m_danceBehavior);
		SetFlyBehavior(std::move(flyBehavior));
	};

	void SetFlyBehavior(std::unique_ptr<IFlyBehavior>&& flyBehavior)
	{
		assert(flyBehavior);
		m_flyBehavior = std::move(flyBehavior);
	}

	void Fly()
	{
		m_flyBehavior->Fly();
	}

	void Quack()
	{
		m_quackBehavior->Quack();
	}

	void Dance()
	{
		m_danceBehavior->Dance();
	}

	void Swim()
	{
		std::cout << "I'm swimming!" << std::endl;
	}

	virtual void Display() const = 0;

	virtual ~Duck() = default;

private:
	std::unique_ptr<IFlyBehavior> m_flyBehavior;
	std::unique_ptr<IQuackBehavior> m_quackBehavior;
	std::unique_ptr<IDanceBehavior> m_danceBehavior;
};

#endif // DUCK_H
