#include "Harl.hpp"

Harl::Harl(const std::string& level) 
{
    _level = level;
}

void    Harl::debug(void)
{
    std::cout << "[ DEBUG ]\n";
    std::cout << "I’m checking every little detail.\n";
    std::cout << "\n";
}

void    Harl::info(void)
{
    std::cout << "[ INFO ]\n";
    std::cout << "The program is running as expected.\n";
    std::cout << "\n";
}

void    Harl::warning(void)
{
    std::cout << "[ WARNING ]\n";
    std::cout << "Something might be wrong, but it’s not critical.\n";
    std::cout << "\n";
}

void    Harl::error(void)
{
    std::cout << "[ ERROR ]\n";
    std::cout << "A serious error occurred. Action is required.\n";
}

void    Harl::standard(void)
{
    std::cout << "[ Probably complaining about insignificant problems ]\n";
}

void    Harl::complain(void)
{
    std::size_t i;
    std::string level[4] = {
        "DEBUG", "INFO", "WARNING", "ERROR"
    };

    i = 0;
    while(i < 4)
    {
        if(level[i] == _level)
            break;
        i++;
    }
    switch (i)
    {
        case 0:
            debug();
            /* fall through */
        case 1:
            info();
            /* fall through */
        case 2:
            warning();
            /* fall through */
        case 3:
            error();
            break;
        default:
            standard();
            break;
    }
}
