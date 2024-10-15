#ifndef DUCK_H
#define DUCK_H

#include <functional>
#include <iostream>

using DanceBehavior = std::function<void()>;
using FlyBehavior = std::function<void()>;
using QuackBehavior = std::function<void()>;

class Duck
{
public:
	Duck(const FlyBehavior& flyBehavior, const QuackBehavior& quackBehavior, const DanceBehavior& danceBehavior)
	{
		m_quackBehavior = quackBehavior;
		m_danceBehavior = danceBehavior;
		SetFlyBehavior(flyBehavior);
	};

	void Fly() const
	{
		if (m_flyBehavior)
		{
			m_flyBehavior();
		}
	}

	void Quack() const
	{
		if (m_quackBehavior)
		{
			m_quackBehavior();
		}
	}

	void Dance() const
	{
		if (m_danceBehavior)
		{
			m_danceBehavior();
		}
	}

	static void Swim()
	{
		std::cout << "I'm swimming!" << std::endl;
	}

	void SetFlyBehavior(const FlyBehavior& flyBehavior)
	{
		m_flyBehavior = flyBehavior;
	};

	virtual void Display() const = 0;

	virtual ~Duck() = default;

private:
	FlyBehavior m_flyBehavior;
	QuackBehavior m_quackBehavior;
	DanceBehavior m_danceBehavior;
};

#endif // DUCK_H
