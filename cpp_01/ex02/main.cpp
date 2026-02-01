#include <string>
#include <iostream>

int main(void)
{
    std::string var;

    var = "HI THIS IS BRAIN";

    std::string*    stringPTR = &var;
    std::string&    stringREF = var;

    std::cout << &var << "\n";
    std::cout << stringPTR << "\n";
    std::cout << &stringREF << "\n";

    std::cout << var << "\n";
    std::cout << *stringPTR << "\n";
    std::cout << stringREF << "\n";
    return (0);
}