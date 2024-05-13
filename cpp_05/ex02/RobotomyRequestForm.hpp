#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    // target 추가?
    private:
        RobotomyRequestForm(const RobotomyRequestForm& obj);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(const std::string& target);
        ~RobotomyRequestForm(void);
        void execute(const Bureaucrat& executor) const;
};

#endif