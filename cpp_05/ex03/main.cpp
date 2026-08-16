#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
    std::cout << "--corret test--\n" << std::endl;
    try
    {
        Bureaucrat  bob("Bob", 20);
        Intern  intern;
        AForm* form = intern.makeForm("shrubbery creation", "cat");

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

    try
    {
        std::cout << "\n--------------------------------\n";
        Bureaucrat  john("John", 10);
        Intern  intern;
        AForm*  form = intern.makeForm("robotomy request", "Niggle");
        std::cout << *form << "\n";
        std::cout << john << "\n";

        john.signForm(*form);
        std::cout << "\n" << *form << "\n";
        john.executeForm(*form);
        john.executeForm(*form);
        std::cout << "\n" << *form << "\n";
        delete form;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    try
    {
        std::cout << "\n--------------------------------\n";
        Bureaucrat  noah("Noah", 4);
        Intern intern;
        AForm*  form = intern.makeForm("presidential pardon", "Gito");
        std::cout << *form << "\n";
        std::cout << noah << "\n";

        noah.signForm(*form);
        std::cout << "\n" << *form << "\n";
        noah.executeForm(*form);
        std::cout << "\n" << *form << "\n";
        delete form;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    std::cout << "--wrong test--\n" << std::endl;
    try
    {
        std::cout << "\n--------------------------------\n";
        Bureaucrat nuno("Nuno", 4);
        Intern intern;
        AForm* form = intern.makeForm("robotomyyy", "Gito");
        std::cout << "\n" << *form << "\n";
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
}
