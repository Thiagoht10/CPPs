#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
    :ClapTrap()
{
    std::cout << "ScavTrap default constructor called\n";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& name)
    :ClapTrap(name)
{
    std::cout << "ScavTrap parameterized constructor called\n";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other)
    :ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap assignment operator called\n";

    if(this != &other)
        ClapTrap::operator=(other);
    return (*this);
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap destructor called\n";
}

void    ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << this->_name
        << " is now in Gate keeper mode." << std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
    if(this->_hitPoints > 0 && this->_energyPoints > 0)
    {
        std::cout << "ScavTrap " << this->_name << " attacks " << target
        << ", causing " << this->_attackDamage << " points of damage!" << std::endl;

        this->_energyPoints--;
    }
    else
    {
        std::cout << "ScavTrap " << this->_name << " is unable to perform attacks"
        << std::endl;
    }
}
