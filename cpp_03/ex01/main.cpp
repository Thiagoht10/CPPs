#include "ScavTrap.hpp"

int main()
{
    {
        ClapTrap bob("Bob");

        bob.attack("Enemy");
        bob.takeDamage(4);
        bob.beRepaired(2);
        bob.takeDamage(20);
        bob.attack("Enemy");
        bob.beRepaired(5);
    }
    std::cout << "\n";
    {
        ScavTrap ruth("Ruth");

        ruth.guardGate();
        ruth.attack("Enemy");
        ruth.takeDamage(42);
        ruth.beRepaired(6);
        ruth.takeDamage(80);
        ruth.attack("Enemy");
        ruth.beRepaired(12);
    }

    return 0;
}