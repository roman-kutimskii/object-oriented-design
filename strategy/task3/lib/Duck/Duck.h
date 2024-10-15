#ifndef DUCK_H
#define DUCK_H

#include <functional>
#include <iostream>

// TODO: Объявить разные using

using Behavior = std::function<void()>;

class Duck
{
public:
	Duck(const Behavior& flyBehavior, const Behavior& quackBehavior, const Behavior& danceBehavior)
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

	void SetFlyBehavior(const Behavior& flyBehavior)
	{
		m_flyBehavior = flyBehavior;
	};

	virtual void Display() const = 0;

	virtual ~Duck() = default;

private:
	Behavior m_flyBehavior;
	Behavior m_quackBehavior;
	Behavior m_danceBehavior;
};

#endif // DUCK_H
