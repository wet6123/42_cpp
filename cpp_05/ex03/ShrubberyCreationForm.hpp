#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
        ShrubberyCreationForm(void);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);
    public:
        ShrubberyCreationForm(const ShrubberyCreationForm& obj);
        ShrubberyCreationForm(const std::string& target);
        ~ShrubberyCreationForm(void);
        void executeChild(void) const;
};

#endif