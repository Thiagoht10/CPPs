#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class Form
{
private:
    const std::string   _name;
    bool                _signed;
    const int           _gradeToSign;
    const int           _gradeToExecute;

public:
    Form(void);
    Form(const std::string& name, int gradeToSign, int gradeToExcetute);
    Form(const Form& other);
    Form&   operator=(const Form& other);
    ~Form();

    const std::string&  getName(void) const;
    bool                getSigned(void) const;
    int           getGradeToSign(void) const;
    int           getGradeToExecute(void) const;

    class GradeTooHighException : public std::exception
    {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char* what() const throw();
    };

    void    beSigned(const Bureaucrat& obj);

};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif