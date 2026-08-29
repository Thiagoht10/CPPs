#include "Array.hpp"
#include <string>
#include <iostream>

int main(void)
{
    try
    {
        int size = 3;
        Array<int> a(size);
        a[0] = 15;
        a[1] = 20;
        a[2] = 25;
        
        Array<int> b;
        Array<int> c(a);
        b = a;
        
        std::cout << "int b: " << std::endl;
        for (int i = 0; i < size; i++)
            std::cout << b[i] << std::endl;
        
        std::cout << "\nint c: " << std::endl;
        for (int i = 0; i < size; i++)
            std::cout << c[i] << std::endl;

        Array<std::string> names(size);
        names[0] = "Norma";
        names[1] = "John";
        names[2] = "Paul";

        std::cout << "\nnames: " << std::endl;
        for (int i = 0; i < size; i++)
            std::cout << names[i] << std::endl;

        std::cout << "\nsize: " << std::endl;
        std::cout << names.size() << std::endl;

        std::cout << names[5] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}