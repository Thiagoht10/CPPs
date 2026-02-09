#include "Sed.hpp"

int main(int argc, char **argv)
{
    std::string filename;
    std::string s1;
    std::string s2;

    if(argc != 4)
    {
        std::cout << RED << "incorrect number of arguments.\n" << RESET;
        return (1);
    }
    filename = argv[1];
    s1 = argv[2];
    s2 = argv[3];

    Sed sed(s1, s2, filename);
    if(!sed.replaceWords())
        return (1);
    return (0);
}