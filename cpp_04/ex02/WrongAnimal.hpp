#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
protected:
    std::string _type;

public:
    WrongAnimal(void);
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal&    operator=(const WrongAnimal& other);
    ~WrongAnimal();

    std::string getType(void) const;
    void        makeSound(void) const;
};

#endif