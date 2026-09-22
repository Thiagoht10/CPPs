#include "BitcoinExchange.hpp"
#include <iostream>

int main(void)
{
    BitcoinExchange dataBase;

    try
    {
        dataBase.loadDatabase("data.csv");
        dataBase.readInput("input.txt");
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
        return 1;
    }

    //dataBase.printAll();

    return 0;
}