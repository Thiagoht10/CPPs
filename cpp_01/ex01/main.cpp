#include "Zombie.hpp"

int main(void)
{
    Zombie* horde;
    int     num;
    int     i;

    num = 3;
    horde = zombieHorde(num, "Foo");
    if(!horde)
        return (0);
    
    i = 0;
    while(i < num)
    {
        horde[i].announce();
        i++;
    }
    delete[] horde;
    return (0);
}
