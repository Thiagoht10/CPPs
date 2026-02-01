#include "Zombie.hpp"

int main(void)
{
    Zombie* z;

    z = newZombie("New Foo");

    randomChump("Foo");
    z->announce();
    delete z;
    return (0);
}
