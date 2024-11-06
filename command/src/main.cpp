#include <iostream>
#include <memory>

#include "History.h"
#include "Menu.h"

int main()
{
    auto menu = std::make_unique<Menu>();
    auto history = std::make_unique<History>();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
