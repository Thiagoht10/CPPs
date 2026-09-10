#include "Base.hpp"
#include <cstdlib>
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
