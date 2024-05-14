#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        ShrubberyCreationForm(const ShrubberyCreationForm& obj);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);
    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(const std::string& target);
        ~ShrubberyCreationForm(void);
        void execute(Bureaucrat const & executor) const;
};

#endif