#include "HumanB.hpp"

HumanB::HumanB(const std::string &name)
{
    this->name = name;
    weapon = NULL;
}

void    HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}

void    HumanB::attack(void)
{
    if(!weapon)
    {
        std::cout << name << " is unarmed" << std::endl;
        return ;
    }
    std::cout << name << " attacks with their " << weapon->getType()
    << std::endl;
}
