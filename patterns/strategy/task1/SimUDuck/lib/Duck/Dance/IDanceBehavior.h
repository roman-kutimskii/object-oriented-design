#ifndef IDANCEBEHAVIOR_H
#define IDANCEBEHAVIOR_H

// Отформатировать код
// Придумать константный метод
struct IDanceBehavior {
    virtual ~IDanceBehavior() = default;

    virtual void Dance() = 0;
};

#endif //IDANCEBEHAVIOR_H
