#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie* z;
    int     i;

    if(N <= 0)
        return (NULL);

    z = new Zombie[N];
    i = 0;
    while(i < N)
    {
        z[i].setName(name);
        i++;
    }
    return (z);
}
