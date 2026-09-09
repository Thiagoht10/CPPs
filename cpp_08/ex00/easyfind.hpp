#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>

template <typename T>
typename T::iterator easyfind(T& container, int find);

#include "easyfind.tpp"

#endif