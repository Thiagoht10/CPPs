#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <exception>
#include "AForm.hpp"

class Intern
{
private:
    AForm*  makeShrubbery(std::string& target);
    AForm*  makeRobotomy(std::string& target);
    AForm*  makePresidential(std::string& target);

public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm*    makeForm(std::string formName, std::string target);

    class FormNotFoundException : public std::exception
    {
    private:
        std::string _message;

    public:
        FormNotFoundException(const std::string& formName);
        ~FormNotFoundException() throw();
        const char* what() const throw();
    };
};

#endif