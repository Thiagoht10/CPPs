#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Form;

class  Bureaucrat
{
private:
    const std::string   _name;
    int                 _grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat&    operator=(const Bureaucrat& other);
    ~Bureaucrat();

    const std::string& getName(void) const;
    int getGrade(void) const;
    
    void    incrementGrade(void);
    void    decrementGrade(void);

    class   GradeTooHighException : public std::exception
    {
    public:
        const char* what() const throw();
    };

    class   GradeTooLowException : public std::exception
    {
    public:
        const char* what() const throw();
    };

    void    signForm(Form& form);
};

std::ostream&   operator<<(std::ostream& os, const Bureaucrat& obj);

#endif