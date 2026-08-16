#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void)
    :_name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    :_name(name), _signed(false),
    _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();

    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other)
    :_name(other._name), _signed(other._signed),
    _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{}

AForm&   AForm::operator=(const AForm& other)
{
    if (this != &other)
        _signed = other._signed;

    return *this;
}

AForm::~AForm()
{}

const std::string& AForm::getName(void) const
{
    return _name;
}

bool    AForm::getSigned(void) const
{
    return _signed;
}

int   AForm::getGradeToSign(void) const
{
    return _gradeToSign;
}

int   AForm::getGradeToExecute(void) const
{
    return _gradeToExecute;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "form grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "form grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "form not signed";
}

void    AForm::beSigned(const Bureaucrat& obj)
{
    if (obj.getGrade() > _gradeToSign)
        throw AForm::GradeTooLowException();

    _signed = true;
}

void    AForm::execute(Bureaucrat const& executor) const
{
    if (!_signed)
        throw AForm::FormNotSignedException();

    if (executor.getGrade() > _gradeToExecute)
        throw AForm::GradeTooLowException();

    executeAction();
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << "name: " << form.getName() << "\n";
    os << "signed: " << (form.getSigned() ? "yes" : "no") << "\n";
    os << "grade to assin: " << form.getGradeToSign() << "\n";
    os << "grade to execute: " << form.getGradeToExecute() << std::endl;

    return os;
}

