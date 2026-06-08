#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(void)
    :_type("none")
{
    std::cout << "AMateria default constructor called\n";
}

AMateria::AMateria(std::string const& type)
    :_type(type)
{
    std::cout << "AMateria parametized constructor called\n";
}

AMateria::AMateria(const AMateria& other)
    :_type(other._type)
{
    std::cout << "AMateria copy constructor called\n";
}

AMateria&   AMateria::operator=(const AMateria& other)
{
    std::cout << "AMateria assignment operator called\n";
    (void)other;
    return (*this);
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called\n";
}

std::string const& AMateria::getType(void) const
{
    return (_type);
}

void    AMateria::use(ICharacter& target)
{
    (void)target;
}