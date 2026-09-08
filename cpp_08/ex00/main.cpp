#include "easyfind.hpp"
#include <vector>
#include <algorithm>
#include <iostream>

int main(void)
{
    std::vector<int> number;

    number.push_back(8);
    number.push_back(9);
    number.push_back(10);

    try
    {
        std::vector<int>::iterator it = easyfind(number, 9);

        std::cout << *it << std::endl;

        std::vector<int>::iterator it_2 = easyfind(number, 15);

        std::cout << *it_2 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    return 0;
}