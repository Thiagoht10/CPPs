#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main()
{
    std::cout << "\n--subject main test--\n" << std::endl;
    {
        IMateriaSource* src = new MateriaSource();

        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter* me = new Character("me");

        AMateria*   tmp;

        tmp = src->createMateria("ice");
        me->equip(tmp);

        tmp = src->createMateria("cure");
        me->equip(tmp);

        ICharacter* bob = new Character("bob");

        me->use(0, *bob);
        me->use(1, *bob);

        delete bob;
        delete me;
        delete src;
    }
    std::cout << "\n--optional test--\n" << std::endl;
    {
        AMateria*   ice = new Ice();
        AMateria*   cure = new Cure();


        ICharacter* me = new Character("me");

        ICharacter* fran = new Character("fran");

        me->equip(ice);
        me->equip(cure);

        me->use(0, *fran);

        me->unequip(0);
        delete ice;

        delete me;
        delete fran;
    }

    return 0;
}
