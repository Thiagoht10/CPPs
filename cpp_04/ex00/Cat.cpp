#include "Cat.hpp"

Cat::Cat(void)
    :Animal()
{
    std::cout << "Cat default constructor called\n";

    this->_type = "Cat";
}

Cat::Cat(const Cat& other)
    :Animal(other)
{
    std::cout << "Cat copy constructor called\n";
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat assignment operator called\n";

    if(this != &other)
        Animal::operator=(other);
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called\n";
}

void    Cat::makeSound(void) const
{
    std::cout << "Meow Meow" << std::endl;
}