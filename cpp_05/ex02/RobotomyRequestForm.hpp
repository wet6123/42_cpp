#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;
        RobotomyRequestForm(void);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
    public:
        RobotomyRequestForm(const RobotomyRequestForm& obj);
        RobotomyRequestForm(const std::string& target);
        ~RobotomyRequestForm(void);
        void executeChild(void) const;
};

#endif