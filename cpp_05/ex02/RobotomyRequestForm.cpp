#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("default")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target)
{}

RobotomyRequestForm&    RobotomyRequestForm::operator=(
            const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }

    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void    RobotomyRequestForm::executeAction(void) const
{
    std::cout << "Briinnnnnnnnn" << "\n";

    static bool seeded = false;

    if (!seeded)
    {
        std::srand(std::time(NULL));
        seeded = true;
    }

    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully\n";
    else
        std::cout << "robotomy failed\n";
}
