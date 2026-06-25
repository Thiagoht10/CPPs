#include "Cure.hpp"
#include <iostream>
#include "ICharacter.hpp"

Cure::Cure(void)
    :AMateria("cure")
{
    std::cout << "Cure default constructor called\n";
}

Cure::Cure(const Cure& other)
    :AMateria(other)
{
    std::cout << "Cure copy constructor called\n";
}

Cure&    Cure::operator=(const Cure& other)
{
    std::cout << "Cure assignment operator called\n";
    if(this != &other)
        AMateria::operator=(other);
    return (*this);
}

Cure::~Cure()
{
    std::cout << "Cure destructor called\n";
}

AMateria*   Cure::clone(void) const
{
    return (new Cure(*this));
}

void    Cure::use(ICharacter& target)
{
    std::cout << "* heals "
        << target.getName()
            << "'s wounds *" << std::endl;
}
