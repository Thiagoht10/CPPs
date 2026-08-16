#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{}

AForm*  Intern::makeShrubbery(std::string& target)
{
    AForm* form = new ShrubberyCreationForm(target);

    std::cout << "Intern creates form ShrubberyCreationForm" << std::endl;
    return form;
}

AForm*  Intern::makeRobotomy(std::string& target)
{
    AForm* form = new RobotomyRequestForm(target);

    std::cout << "Intern creates form RobotomyRequestForm" << std::endl;
    return form;
}

AForm*  Intern::makePresidential(std::string& target)
{
    AForm* form = new PresidentialPardonForm(target);

    std::cout << "Intern creates form PresidentialPardonForm" << std::endl;
    return form;
}

AForm*  Intern::makeForm(std::string formName, std::string target)
{
    std::string name[3] = {"shrubbery creation", "robotomy request",
    "presidential pardon"};

    AForm*  (Intern::*function[3])(std::string& name) = {
        &Intern::makeShrubbery, &Intern::makeRobotomy, &Intern::makePresidential
    };

    for (int i = 0; i < 3; i++)
    {
        if (name[i] == formName)
            return (this->*function[i])(target);
    }
    
    throw Intern::FormNotFoundException(formName);
}
Intern::FormNotFoundException::FormNotFoundException(const std::string& formName)
{
    _message.append("Intern cannot create form: ");
    _message.append(formName);
}

Intern::FormNotFoundException::~FormNotFoundException() throw()
{}

const char* Intern::FormNotFoundException::what() const throw()
{
    return _message.c_str();
}