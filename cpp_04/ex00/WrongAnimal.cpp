#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
    :_type("none")
{
    std::cout << "Wrong animal default constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
    :_type(other._type)
{
    std::cout << "Wrong animal copy constructor called\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "WrongAnimal assignment operator called\n";

    if(this != &other)
        _type = other._type;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Wrong animal destructor called\n";
}

std::string WrongAnimal::getType(void) const
{
    return (_type);
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << "Some generic animal sound" << std::endl;
}
