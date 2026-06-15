#include "Base.hpp"
#include <iostream>

int main()
{
    std::cout << "Generating a random Base object..." << std::endl;
    Base *base = generate();

    std::cout << "Identifying the type of the generated object..." << std::endl;
    std::cout << "The actual type of the object pointed to by p is: ";
    identify(base);
    std::cout << "The actual type of the object passed by reference is: ";
    identify(*base);
    delete base;
    return 0;
}