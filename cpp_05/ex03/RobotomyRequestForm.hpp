#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <cstdlib>
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
        static AForm* clone(const std::string& target);
};

#endif