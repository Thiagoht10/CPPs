#include "BitcoinExchange.hpp"

int main(void)
{
    BitcoinExchange dataBase;

    if (!dataBase.loadDatabase("data.csv"))
        return 1;
    if (dataBase.readInput("input.txt"))
        return 1;

    dataBase.printAll();

    return 0;
}