#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
: AForm("robotomy request", 72, 45)
{
    this->target = obj.target;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("robotomy request", 72, 45)
{
    this->target = target;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{}

void RobotomyRequestForm::executeChild(void) const
{
    std::cout << "*drilling noises*\n";
    
    if (std::rand() % 2)
        std::cout << this->target << " has been robotomized\n";
    else
        std::cout << "Robotomization failed\n";
}

AForm* RobotomyRequestForm::clone(const std::string& target)
{
    return (new RobotomyRequestForm(target));
}