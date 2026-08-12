#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <string>
#include "AForm.hpp"
#include <exception>

class ShrubberyCreationForm : public AForm
{
private:
    std::string _target;

protected:
    void    executeAction(void) const;

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm&  operator=(const ShrubberyCreationForm& other);
    virtual ~ShrubberyCreationForm();

    class FileCreationException : std::exception
    {
    public:
        const char* what() const throw();
    };
    
};

#endif