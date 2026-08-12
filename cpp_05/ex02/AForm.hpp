#ifndef A_FORM_HPP
#define A_FORM_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm
{
private:
    const std::string   _name;
    bool                _signed;
    const int           _gradeToSign;
    const int           _gradeToExecute;

protected:
    virtual void    executeAction(void) const = 0;


public:
    AForm(void);
    AForm(const std::string& name, int gradeToSign, int gradeToExcetute);
    AForm(const AForm& other);
    AForm&   operator=(const AForm& other);
    virtual ~AForm();

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
    
    class FormNotSignedException : public std::exception
    {
        public:
        const char* what() const throw();
    };
    
    void    beSigned(const Bureaucrat& obj);
    void    execute(Bureaucrat const& executor) const;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif