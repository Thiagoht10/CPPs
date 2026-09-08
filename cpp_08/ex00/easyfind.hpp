#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class IntegerNotFoundException : public std::exception
{
public:
    const char* what() const throw()
    {
        return "Integer not found";
    }
};

template <typename T>
typename T::iterator easyfind(T& container, int find)
{
    typename T::iterator it = std::find(container.begin(), container.end(), find);

    if (it != container.end())
        return it;
    else
        throw IntegerNotFoundException();

}

#endif
