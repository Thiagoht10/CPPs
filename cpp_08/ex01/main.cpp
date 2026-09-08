#include "Span.hpp"
#include <iostream>

int main()
{
    std::cout << "-------------corret test-----------------" << std::endl;
    try
    {
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;


        std::vector<int> tmp;

        for (int i = 0; i < 10000; i++)
            tmp.push_back(i);

        Span sn(10000);

        sn.addNumber(tmp.begin(), tmp.end());

        std::cout << sn.shortestSpan() << std::endl;
        std::cout << sn.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    std::cout << "\n-------------wrong test-----------------" << std::endl;
    try
    {
        Span st(1);

        st.addNumber(8);
        st.addNumber(15);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    try
    {
        Span st(1);

        st.longestSpan();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    try
    {
        Span st(1);

        st.shortestSpan();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    
    return 0;
}