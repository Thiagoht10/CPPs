#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    std::cout << "--corret test--\n" << std::endl;
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

    try
    {
        std::cout << "\n--------------------------------\n";
        Bureaucrat  john("John", 10);
        AForm*  form = new RobotomyRequestForm("Niggle");
        std::cout << *form << "\n";
        std::cout << john << "\n";

        john.signForm(*form);
        std::cout << "\n" << *form << "\n";
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
        AForm*  form = new PresidentialPardonForm("Gito");
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

    std::cout << "\n--wrong test--\n" << std::endl;
   
    try
    {
        std::cout << "\n--------------------------------\n";
        Bureaucrat john("John", 8);
        AForm* form = new PresidentialPardonForm("Gito");
        std::cout << *form << "\n";
        std::cout << john << "\n";

        john.executeForm(*form);
        delete form;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    try
    {
        std::cout << "\n--------------------------------\n";
        Bureaucrat john("John", 10);
        AForm* form = new PresidentialPardonForm("Gito");
        std::cout << *form << "\n";
        std::cout << john << "\n";

        john.signForm(*form);
        std::cout << "\n" << *form << "\n";

        john.executeForm(*form);
        delete form;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    
}
