#include "WrongCat.hpp"

WrongCat::WrongCat(void)
    :WrongAnimal()
{
    std::cout << "WrongCat default constructor called\n";

    this->_type = "Cat";
    _brain = new Brain;
}

WrongCat::WrongCat(const WrongCat& other)
    :WrongAnimal(other)
{
    std::cout << "WrongCat copy constructor called\n";

    _brain = new Brain(*other._brain);
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "WrongCat assignment operator called\n";

    if(this != &other)
    {
        WrongAnimal::operator=(other);
        *_brain = *other._brain;
    }
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called\n";
    delete _brain;
}

void    WrongCat::makeSound(void) const
{
    std::cout << "Meow Meow" << std::endl;
}
