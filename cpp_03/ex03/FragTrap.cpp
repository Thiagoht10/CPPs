#include "FragTrap.hpp"

FragTrap::FragTrap(void)
    :ClapTrap()
{
    std::cout << "FragTrap default constructor called\n";

    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(const std::string& name)
    :ClapTrap(name)
{
    std::cout << "FragTrap parameterized constructor called\n";

    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other)
    :ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called\n";
}

FragTrap&   FragTrap::operator=(const FragTrap& other)
{
    std::cout << "FragTrap assignment operator called\n";

    if(this != &other)
        ClapTrap::operator=(other);
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called\n";
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->_name
        << " requests a positive high five!" << std::endl; 
}
