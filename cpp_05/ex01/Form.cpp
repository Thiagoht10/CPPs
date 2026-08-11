#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void)
    :_name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    :_name(name), _signed(false),
    _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();

    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& other)
    :_name(other._name), _signed(other._signed),
    _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{}

Form&   Form::operator=(const Form& other)
{
    if (this != &other)
        _signed = other._signed;

    return *this;
}

Form::~Form()
{}

const std::string& Form::getName(void) const
{
    return _name;
}

bool    Form::getSigned(void) const
{
    return _signed;
}

int   Form::getGradeToSign(void) const
{
    return _gradeToSign;
}

int   Form::getGradeToExecute(void) const
{
    return _gradeToExecute;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "form grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "form grade is too low";
}

void    Form::beSigned(const Bureaucrat& obj)
{
    if (obj.getGrade() > _gradeToSign)
        throw Form::GradeTooLowException();

    _signed = true;
}

std::ostream& operator<<(std::ostream& os, Form& form)
{
    os << "name: " << form.getName() << "\n";
    os << "signed: " << (form.getSigned() ? "yes" : "no") << "\n";
    os << "grade to assin: " << form.getGradeToSign() << "\n";
    os << "grade to execute: " << form.getGradeToExecute() << std::endl;

    return os;
}

