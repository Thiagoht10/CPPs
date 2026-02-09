#ifndef SED_HPP
#define SED_HPP

#include <string>
#include <iostream>
#include <fstream>

#define RED     "\033[31m"
#define RESET   "\033[0m"

class Sed
{
private:
    std::string s1;
    std::string s2;
    std::string filename;

    bool    openFile(std::ifstream& in, std::ofstream& out);
    bool    checkArg(void) const;

public:
    Sed(std::string s1, std::string s2, std::string filename);
    
    bool    replaceWords(void);
};


#endif