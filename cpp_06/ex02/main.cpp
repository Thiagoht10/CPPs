#include "Base.hpp"
#include <ctime>

int main(void)
{
    std::srand(std::time(NULL));

    Base* base = generate();

    identify(base);
    identify(*base);

    delete base;
    return 0;
}