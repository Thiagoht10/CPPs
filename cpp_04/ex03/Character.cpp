#include "Character.hpp"
#include <iostream>

Character::Character(void)
    :_name("none")
{
    std::cout << "Character default constructor called\n";

    for(int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character(std::string const& name)
    :_name(name)
{
    std::cout << "Character parametized constructor called\n";

    for(int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character(const Character& other)
    :_name(other._name)
{
    std::cout << "Character copy constructor called\n";

    for(int i = 0; i < 4; i++)
    {
        if (other._inventory)
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
}

Character&  Character::operator=(const Character& other)
{
    std::cout << "Character assignment operator called\n";

    if(this != &other)
    {
        _name = other._name;

        for (int i = 0; i < 4; i++)
        {
            delete _inventory[i];
            _inventory[i] = NULL;
        }

        for (int i = 0; i < 4; i++)
        {
            if (other._inventory)
                _inventory[i] = other._inventory[i]->clone();
        }
    }
    return (*this);
}

Character::~Character()
{
    std::cout << "Character destructor called\n";

    for (int i = 0; i < 4; i++)
    {
        delete _inventory[i];
        _inventory[i] = NULL;
    }
}