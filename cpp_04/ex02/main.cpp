#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "\n--Correct animal test--\n" << std::endl;
    {
        int i = 0;
        Animal*  animal[4];

        while(i < 2)
            animal[i++] = new Dog;
        while (i < 4)
            animal[i++] = new Cat;

        for(int j = 0; j < 4; j++)
        {
            std::cout << animal[j]->getType() << std::endl;
            animal[j]->makeSound();
        }

        for(int j = 0; j < 4; j++)
            delete animal[j];
    }
    std::cout << "\n--Deep copy test--\n" << std::endl;
    {
        Dog dog1;
        Dog dog2;
        Cat cat1;
        Cat cat2;

        dog1.setBrainIdea(10, "I wanna eat");
        cat1.setBrainIdea(10, "I wanna play");

        dog2 = dog1;
        cat2 = cat1;

        std::cout << "\n" << "Idea dog1: " << dog1.getBrainIdea(10) << std::endl;
        std::cout << "Idea dog2: " << dog2.getBrainIdea(10) << "\n" << std::endl;
        std::cout << "Idea cat1: " << cat1.getBrainIdea(10) << std::endl;
        std::cout << "Idea cat2: " << cat2.getBrainIdea(10) << "\n" << std::endl;

        dog2.setBrainIdea(10, "I wanna sleep");
        cat2.setBrainIdea(10, "I wanna hunt");

        std::cout << "\n" << "Idea dog1: " << dog1.getBrainIdea(10) << std::endl;
        std::cout << "Idea dog2: " << dog2.getBrainIdea(10) << "\n" << std::endl;
        std::cout << "Idea cat1: " << cat1.getBrainIdea(10) << std::endl;
        std::cout << "Idea cat2: " << cat2.getBrainIdea(10) << "\n" << std::endl;
    }
    /* std::cout << "\n--Abstract Animal test--\n" << std::endl;
    {
        Animal* animal = new Animal;

        animal->makeSound();
        delete animal;
    } */
    return 0;
}
