#include "easyfind.hpp"
#include <algorithm>

#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int find)
{
    typename T::iterator it = std::find(container.begin(), container.end(), find);

    if (it != container.end())
        return it;
    else
        throw std::runtime_error("Integer not found");

}
