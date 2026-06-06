#include "Dog.hpp"

Dog::Dog(void)
    :Animal()
{
    std::cout << "Dog default constructor called\n";

    this->_type = "Dog";
    _brain = new Brain;
}

Dog::Dog(const Dog& other)
    :Animal(other)
{
    std::cout << "Dog copy constructor called\n";
    _brain = new Brain(*other._brain);
}

Dog&    Dog::operator=(const Dog& other)
{
    std::cout << "Dog assignment operator called\n";

    if(this != &other)
    {
        Animal::operator=(other);
        *_brain = *other._brain;
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called\n";

    delete _brain;
}

void    Dog::makeSound(void) const
{
    std::cout << "Woof Woof" << std::endl;
}


void    Dog::setBrainIdea(int index, std::string idea)
{
    _brain->setIdea(index, idea);
}

std::string Dog::getBrainIdea(int index) const
{
    return (_brain->getIdea(index));
}