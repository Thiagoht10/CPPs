#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void    iter(T* array, const size_t lenght, void (*func)(T &))
{
    for (size_t i = 0; i < lenght; i++)
        func(array[i]);
}

template <typename T>
void    iter(const T* array, const size_t lenght, void (*func)(const T&))
{
    for (size_t i = 0; i < lenght; i++)
        func(array[i]);
}

template <typename T>
void    print(T& array)
{
    std::cout << array << std::endl;
}

template <typename T>
void    show(const T& array)
{
    std::cout << array << std::endl;
}

#endif
