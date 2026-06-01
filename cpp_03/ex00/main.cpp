#include "ClapTrap.hpp"

int main()
{
    ClapTrap bob("Bob");

    bob.attack("Enemy");
    bob.takeDamage(4);
    bob.beRepaired(2);
    bob.takeDamage(20);
    bob.attack("Enemy");
    bob.beRepaired(5);

    return 0;
}