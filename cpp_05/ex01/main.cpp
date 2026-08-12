#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    std::cout << "--corret test--\n" << std::endl;
    {
        try
        {
            Bureaucrat  bob("Bob", 15);
            AForm        form("AForm", 22, 20);
            
            std::cout << form << "\n";
            std::cout << bob << "\n";
            
            bob.signForm(form);
            std::cout << "\n" << form << "\n";
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
    }

    std::cout << "\n--wrong test--\n" << std::endl;
    {
        try
        {
            Bureaucrat john("John", 160);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }

        try
        {
            AForm    form("AForm", 0, 0);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }

        try
        {
            Bureaucrat noah("Noah", 50);
            AForm form("THT", 25, 16);

            noah.signForm(form);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
    }
}
