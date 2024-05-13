#include "ShrubberyCreationForm.hpp"

// ShrubberyCreationForm(const ShrubberyCreationForm& obj)
// ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);

ShrubberyCreationForm::ShrubberyCreationForm(void)
: AForm("default_shrubbery", 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm(target + "_shrubbery", 145, 137)
{}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    // check executable
    // create <target>_shruberry file
    std::ofstream file(getName().c_str());
    
    if (file.is_open())
    {
        // write ASCII tress
        file << "            /\\" << "\n";
        file << "           /  \\" << "\n";
        file << "          /    \\" << "\n";
        file << "         /      \\" << "\n";
        file << "        /        \\" << "\n";
        file << "           |  |" << "\n";
        file.close();
    }
    else
    {
        std::cout << "Failed to create file\n";
        return ;
    }
}