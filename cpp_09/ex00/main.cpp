#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange dataBase;

    try
    {
        dataBase.loadDatabase("data.csv");
        if (dataBase.isEmpty())
        {
            std::cout << "database is empty" << std::endl;
            return 1;
        }
        dataBase.readInput(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
        return 1;
    }

    //dataBase.printAll();

    return 0;
}