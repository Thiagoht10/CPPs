#include "Weapon.hpp"

Weapon::Weapon(const std::string &type)
{
    this->type = type;
}

std::string Weapon::getType() const
{
    const std::string& refType = type;
    return (refType);
}

void    Weapon::setType(const std::string &type)
{
    this->type = type;
}