#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    PmergeMe sort;

    if (argc < 2)
    {
        std::cerr << "error" << std::endl;
        return 1;
    }

    try
    {
        sort.execute(argv);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }

    sort.printAll();
    
    return 0;
}