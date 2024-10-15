#ifndef IDANCEBEHAVIOR_H
#define IDANCEBEHAVIOR_H

// TODO: Придумать константный метод, который можно здесь использовать

struct IDanceBehavior
{
	virtual ~IDanceBehavior() = default;

	virtual void Dance() = 0;
};

#endif // IDANCEBEHAVIOR_H
