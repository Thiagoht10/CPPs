#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "--correct test--\n" << std::endl;
    {
        try
        {
            Bureaucrat a("Olivia", 10);
            std::cout << a << "\n";

            a.incrementGrade();
            std::cout << a << "\n";

            a.decrementGrade();
            a.decrementGrade();
            std::cout << a << "\n";

            Bureaucrat b;

            b = a;
            std::cout << b << "\n";
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
    }

    std::cout << "\n--incorret test--\n" << std::endl;
    {
        try
        {
            Bureaucrat b("John", 0);
            std::cout << b << "\n";
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }

        try
        {
            Bureaucrat b("John", 190);
            std::cout << b << "\n";
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }

        try
        {
            Bureaucrat b("Noah", 1);
            std::cout << b << "\n";

            b.incrementGrade();
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }

        try
        {
            Bureaucrat b("Mathew", 150);
            std::cout << b << "\n";

            b.decrementGrade();
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
    }
}
