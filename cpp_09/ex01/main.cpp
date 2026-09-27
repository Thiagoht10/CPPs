#include "RPN.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    RPN calculator;

    if (argc != 2)
    {
        std::cerr << "wrong number of arguments" << std::endl;
        return 1;
    }

    try
    {
        calculator.execute(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    
    return 0;
}