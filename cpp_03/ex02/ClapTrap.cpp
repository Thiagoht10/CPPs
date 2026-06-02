#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
    :_name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Default constructor called\n";
}

ClapTrap::ClapTrap(const std::string& name)
    :_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Parameterized constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "Copy constructor called\n";
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
}

ClapTrap&   ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "Assignment operator called\n";
    if(this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return (*this);
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "Destructor called\n";
}

void    ClapTrap::attack(const std::string& target)
{
    if(_hitPoints > 0 && _energyPoints > 0)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target
        << ", causing " << _attackDamage << " points of damage!" << std::endl;

        _energyPoints--;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " is unable to perform attacks"
        << std::endl;
    }
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if(_hitPoints > 0)
    {
        std::cout << "ClapTrap " << _name << " takes " << amount
        << " points of damage" << std::endl;

        if(amount >= _hitPoints)
            _hitPoints = 0;
        else
            _hitPoints -= amount;
    }
    else
        std::cout << "ClapTrap " << _name << " already is dead" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if(_hitPoints > 0 && _energyPoints > 0)
    {
        std::cout << "ClapTrap " << _name << " recovered " << amount
        << " points" << std::endl;

        _energyPoints--;
        _hitPoints += amount;
    }
    else
        std::cout << "ClapTrap " << _name << " is unable to recover" << std::endl;
}