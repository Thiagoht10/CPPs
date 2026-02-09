#include "Harl.hpp"

Harl::Harl() {};

void    Harl::debug(void)
{
    std::cout << "I’m checking every little detail, even the ones nobody asked for.\n";
}

void    Harl::info(void)
{
    std::cout << "Just so you know, everything is running exactly as planned.\n";
}

void    Harl::warning(void)
{
    std::cout << "This might become a problem later… but let’s pretend it won’t.\n";
}

void    Harl::error(void)
{
    std::cout << "Everything is broken. This is serious. Fix it. Now.\n";
}

void    Harl::complain(std::string level)
{
    int i;

    std::string list_level[4] = {
        "DEBUG", "INFO", "WARNING", "ERROR"
    };

    void (Harl::*functions[4])(void) = {
        &Harl::debug, &Harl::info, &Harl::warning, &Harl::error
    };

    i = 0;
    while(i < 4)
    {
        if (level == list_level[i])
        {
            (this->*functions[i])();
            return ;
        }
        i++;
    }
    std::cout << "level not found\n";
}