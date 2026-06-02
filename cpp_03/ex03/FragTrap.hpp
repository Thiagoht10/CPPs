#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
    FragTrap(void);
    FragTrap(const std::string& name);
    FragTrap(const FragTrap& other);
    FragTrap&   operator=(const FragTrap& other);
    ~FragTrap();

    void highFivesGuys(void);
};


#endif
