#include "Harl.hpp"

int main(int argc, char **argv)
{
    std::string level;

    if(argc != 2)
    {
        std::cout << RED << "Please, specify a level\n" << RESET;
        return (1);
    }

    level = argv[1];
    Harl harl(level);
    harl.complain();
    return (0);
}
