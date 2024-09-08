#ifndef DUCK_H
#define DUCK_H

#include <cassert>
#include <iostream>
#include <memory>

#include "Fly/IFlyBehavior.h"
#include "Quack/IQuackBehavior.h"

class Duck {
public:
    Duck(std::unique_ptr<IFlyBehavior> &&flyBehavior, std::unique_ptr<IQuackBehavior> &&quackBehavior)
        : m_quackBehavior(std::move(quackBehavior)) {
        assert(m_quackBehavior);
        SetFlyBehavior(std::move(flyBehavior));
    };

    void SetFlyBehavior(std::unique_ptr<IFlyBehavior> &&flyBehavior) {
        assert(flyBehavior);
        m_flyBehavior = std::move(flyBehavior);
    }

    void Quack() const {
        m_quackBehavior->Quack();
    }

    void Fly() const {
        m_flyBehavior->Fly();
    }

    static void Swim() {
        std::cout << "I'm swimming!" << std::endl;
    }

    virtual void Dance() {
        std::cout << "I'm dancing!" << std::endl;
    }

    virtual void Display() const = 0;

    virtual ~Duck() = default;

private:
    std::unique_ptr<IFlyBehavior> m_flyBehavior;
    std::unique_ptr<IQuackBehavior> m_quackBehavior;
};

#endif //DUCK_H
