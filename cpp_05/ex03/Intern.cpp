#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define OBJ_CNT 3

Intern::Intern(void)
{}

Intern::~Intern(void)
{}

AForm& Intern::makeForm(const std::string& formName, const std::string& target)
{
	const std::string name[OBJ_CNT] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (*f[])(const std::string& target) = {
		&ShrubberyCreationForm::clone,
		&RobotomyRequestForm::clone,
		&PresidentialPardonForm::clone
	};

	// AForm * (*f)(const std::string &) = ShrubberyCreationForm::clone;
	for (int i = 0; i < OBJ_CNT; i++)
	{
		if (name[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (*f[i](target));
		}
	}
	throw Intern::FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return ("Form not found.");
}