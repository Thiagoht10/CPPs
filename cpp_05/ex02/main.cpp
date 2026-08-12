#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    std::cout << "--corret test--\n" << std::endl;
    {
        try
        {
            Bureaucrat  bob("Bob", 20);
            AForm* form = new ShrubberyCreationForm("Cat");
            
            std::cout << *form << "\n";
            std::cout << bob << "\n";
            
            bob.signForm(*form);
            std::cout << "\n" << *form << "\n";

            bob.executeForm(*form);
            std::cout << "\n" << *form << "\n";

            delete form;
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
    }
}
