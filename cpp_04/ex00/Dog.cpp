#include "Dog.hpp"

Dog::Dog(void)
    :Animal()
{
    std::cout << "Dog default constructor called\n";

    this->_type = "Dog";
}

Dog::Dog(const Dog& other)
    :Animal(other)
{
    std::cout << "Dog copy constructor called\n";
}

Dog&    Dog::operator=(const Dog& other)
{
    std::cout << "Dog assignment operator called\n";

    if(this != &other)
        Animal::operator=(other);
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called\n";
}

void    Dog::makeSound(void) const
{
    std::cout << "Woof Woof" << std::endl;
}
