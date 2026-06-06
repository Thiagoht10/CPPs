#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain* _brain;

public:
    Cat(void);
    Cat(const Cat& other);
    Cat&    operator=(const Cat& other);
    ~Cat();

    void    makeSound(void) const;

    void        setBrainIdea(int index, std::string idea);
    std::string getBrainIdea(int index) const;
};


#endif
