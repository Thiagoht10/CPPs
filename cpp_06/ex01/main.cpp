#include "Serializer.hpp"
#include <iostream>

int main(void)
{
    Data data;
    uintptr_t   raw;
    Data*       result;

    data.name = "teste";
    data.value = 10;

    Data*   prt = &data;

    std::cout << "original: " << prt << "\n" << std::endl;
    
    raw = Serializer::serialize(prt);
    result = Serializer::deserialize(raw);

    std::cout << raw << std::endl;
    std::cout << result << std::endl;

    if (result == prt)
        std::cout << "result is equal prt" << std::endl;
    else
        std::cout << "result not is equal prt" << std::endl;
    
    return 0;
}