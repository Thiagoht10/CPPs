#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

#define RED "\033[31m"
#define RESET "\033[0m"

class Harl
{
private:
    std::string _level;

    void    debug(void);
    void    info(void);
    void    warning(void);
    void    error(void);
    void    standard(void);

public:
    Harl(const std::string& level);

    void complain(void);
};


#endif