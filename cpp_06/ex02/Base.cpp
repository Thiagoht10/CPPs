#include "Base.hpp"
#include <iostream>
#include <exception>

Base::~Base()
{}

Base* generate(void)
{
    int random = std::rand() % 3;

    if (random == 0)
        return new A;
    if (random == 1)
        return new B;
    return new C;
}

void    identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void    identify(Base& p)
{
    try
    {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch(const std::exception& e)
    {}

    try
    {
        dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    }
    catch(const std::exception& e)
    {}

    try
    {
        dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    }
    catch(const std::exception& e)
    {}
    
}