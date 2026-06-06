#include "Animal.hpp"

Animal::Animal(void)
    :_type("none")
{
    std::cout << "Animal default constructor called\n";
}

Animal::Animal(const Animal& other)
    :_type(other._type)
{
    std::cout << "Animal copy constructor called\n";
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal assignment operator called\n";

    if(this != &other)
        _type = other._type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructor called\n";
}

std::string Animal::getType(void) const
{
    return (_type);
}

/* void    Animal::makeSound(void) const
{
    std::cout << "Some generic animal sound" << std::endl;
} */
