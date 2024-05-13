#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
: AForm("default_robotomy", 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm(target + "_robotomy", 72, 45)
{}

RobotomyRequestForm::~RobotomyRequestForm(void)
{}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    std::cout << "*drilling noises*\n";
    
    if (std::rand() % 2)
        std::cout << getName() << " has been robotomized\n";
    else
        std::cout << "Robotomization failed\n";
}