#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
    std::string name;

public:
    void    announce(void);
    void    setName(const std::string &name);

    Zombie();
    ~Zombie();
};

Zombie*     zombieHorde(int N, std::string name);

#endif