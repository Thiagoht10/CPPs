#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(void)
{
    std::cout << "MateriaSource default constructor called\n";

    for (int i = 0; i < 4; i++)
        _materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    std::cout << "MateriaSource copy constructor called\n";

    for (int i = 0; i < 4; i++)
    {
        if (other._materias[i])
            _materias[i] = other._materias[i]->clone();
        else
            _materias[i] = NULL;
    }
}

MateriaSource&  MateriaSource::operator=(const MateriaSource& other)
{
    std::cout << "MateriaSource assignment operator called\n";

    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            delete _materias[i];
            _materias[i] = NULL;
        }

        for (int i = 0; i < 4; i++)
        {
            if (other._materias[i])
                _materias[i] = other._materias[i]->clone();
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destructor operator called\n";

    for (int i = 0; i < 4; i++)
    {
        if(_materias[i])
        {
            delete _materias[i];
            _materias[i] = NULL;
        }
    }
}

void    MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return;

    for (int i = 0; i < 4; i++)
    {
        if (_materias[i] == NULL)
        {
            _materias[i] = m->clone();
            delete m;
            return;
        }
    }
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_materias[i] && _materias[i]->getType() == type)
            return (_materias[i]->clone());
    }
    return (NULL);
}
