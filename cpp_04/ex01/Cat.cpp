#include "Cat.hpp"

Cat::Cat(void)
    :Animal()
{
    std::cout << "Cat default constructor called\n";

    this->_type = "Cat";
    _brain = new Brain;
}

Cat::Cat(const Cat& other)
    :Animal(other)
{
    std::cout << "Cat copy constructor called\n";
    _brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat assignment operator called\n";

    if(this != &other)
    {
        Animal::operator=(other);
        *_brain = *other._brain;
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called\n";
    
    delete _brain;
}

void    Cat::makeSound(void) const
{
    std::cout << "Meow Meow" << std::endl;
}

void    Cat::setBrainIdea(int index, std::string idea)
{
    _brain->setIdea(index, idea);
}

std::string Cat::getBrainIdea(int index) const
{
    return (_brain->getIdea(index));
}
