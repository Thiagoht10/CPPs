#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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
    std::cout << "\n";
    {
        FragTrap noah("Noah");

        noah.highFivesGuys();
        noah.attack("Enemy");
        noah.takeDamage(37);
        noah.beRepaired(2);
        noah.takeDamage(75);
        noah.attack("Enemy");
        noah.beRepaired(24);
    }
    std::cout << "\n";
    {
        DiamondTrap dimmy("Dimmy");
        DiamondTrap jhon(dimmy);

        std::cout << "\n";

        jhon.whoAmI();
        jhon.attack("Enemy");
        jhon.takeDamage(48);
        jhon.beRepaired(3);
        jhon.takeDamage(57);
        jhon.attack("Enemy");
        jhon.beRepaired(30);
    }

    return 0;
}
