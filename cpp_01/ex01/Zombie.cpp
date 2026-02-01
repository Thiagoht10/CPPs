#include "Zombie.hpp"

Zombie::Zombie(){}

void    Zombie::setName(const std::string &name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << name << ": Zombie destroited\n";
}

void    Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
