#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
    :ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(), _name("Default")
{
    std::cout << "DiamondTrap default constructor called\n";

    this->_hitPoints = 100;     // FragTrap
    this->_energyPoints = 50;   // ScavTrap
    this->_attackDamage = 30;   // FragTrap
}

DiamondTrap::DiamondTrap(const std::string& name)
    :ClapTrap(name + "_clap_name"), ScavTrap(name), 
        FragTrap(name), _name(name)
{
    std::cout << "DiamondTrap parameterized constructor called\n";

    this->_hitPoints = 100;     // FragTrap
    this->_energyPoints = 50;   // ScavTrap
    this->_attackDamage = 30;   // FragTrap
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    :ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name)
{
    std::cout << "DiamondTrap copy constructor called\n";
}

DiamondTrap&    DiamondTrap::operator=(const DiamondTrap& other)
{
    std::cout << "DiamondTrap assignment operator called\n";

    if(this != &other)
    {
        ClapTrap::operator=(other);
        _name = other._name;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called\n";
}

void    DiamondTrap::whoAmI(void)
{
    std::cout << "DiamondTrap name: " << _name << std::endl;
    std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}

void    DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}
