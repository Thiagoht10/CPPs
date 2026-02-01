#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
    std::string name;
    Weapon*     weapon;

public:
    HumanB(const std::string& name);

    void    setWeapon(Weapon& weapon);
    void    attack(void);
};


#endif