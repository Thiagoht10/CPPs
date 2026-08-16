#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
            const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }

    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void    ShrubberyCreationForm::executeAction(void) const
{
    std::string filename = _target + "_shrubbery";

    std::ofstream   file(filename.c_str());

    if (!file.is_open())
        throw ShrubberyCreationForm::FileCreationException();

    file << "   &&& &&  & &&" << std::endl;
    file << " && &\\/&\\|& ()|/ @, &&" << std::endl;
    file << " &\\/(/&/&||/& /_/)_&/_&" << std::endl;
    file << "  &() &\\/&|()|/&\\/ '%\" & ()" << std::endl;
    file << " &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
    file << "&&   && & &| &| /& & % ()& /&&" << std::endl;
    file << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
    file << "     &&     \\|||" << std::endl;
    file << "             |||" << std::endl;
    file << "             |||" << std::endl;
    file << "             |||" << std::endl;
}

const char* ShrubberyCreationForm::FileCreationException::what() const throw()
{
    return "file to open file";
}