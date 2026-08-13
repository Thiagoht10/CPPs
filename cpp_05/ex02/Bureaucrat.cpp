#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat()
    : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    :_name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();

    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();

    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    :_name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        _grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName(void) const
{
    return _name;
}

int Bureaucrat::getGrade(void) const
{
    return _grade;
}

void    Bureaucrat::incrementGrade(void)
{
    if (_grade <= 1)
        throw Bureaucrat::GradeTooHighException();

    _grade--;
}

void    Bureaucrat::decrementGrade(void)
{
    if (_grade >= 150)
        throw Bureaucrat::GradeTooLowException();

    _grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat is too low";
}

std::ostream&   operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << obj.getName();
    os << ", bureaucrat grade ";
    os << obj.getGrade() << ".";

    return os;
}

void    Bureaucrat::signForm(AForm& form)
{
    try
    {
        form.beSigned(*this);

        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << _name << " couldn't sign "
        << form.getName() << " because "
        << e.what() << std::endl;
    }
    
}

void    Bureaucrat::executeForm(AForm const& form) const
{
    try
    {
        form.execute(*this);

        std::cout << _name << " executed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << _name << " couldn't execute "
        << form.getName() << " because "
        << e.what() << std::endl;
    }
    
}
