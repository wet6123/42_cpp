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
	AForm* (AForm::*f[OBJ_CNT])(const std::string& target) = ;

	for (int i = 0; i < OBJ_CNT; i++)
	{

	}
}