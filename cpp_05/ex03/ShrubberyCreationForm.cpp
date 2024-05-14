#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
: AForm("shrubbery creation", 145, 137)
{
    this->target = obj.target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("shrubbery creation", 145, 137)
{
    this->target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{}

void ShrubberyCreationForm::executeChild(void) const
{
    // create <target>_shruberry file
    std::ofstream file((this->target + "_shrubbery").c_str());
    
    if (file.is_open())
    {
        // write ASCII tress
        file << "            /\\                /\\    " << "\n";
        file << "           /  \\          /\\  /  \\   " << "\n";
        file << "          /    \\        /  \\/    \\  " << "\n";
        file << "         /      \\      /   /      \\ " << "\n";
        file << "        /        \\    /   /        \\" << "\n";
        file << "           |  |          ||  |  |    " << "\n";
        file.close();
    }
    else
    {
        std::cout << "Failed to create file\n";
    }
}

AForm* clone(const std::string& target)
{
    return (new ShrubberyCreationForm(target));
}