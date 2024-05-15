#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
    try
	{
		Bureaucrat junsbae("junsbae", 1);
		Intern intern;
		AForm *shrubberyForm = intern.makeForm("shrubbery creation", "home");

		// ShrubberyCreationForm
		junsbae.signForm(shrubberyForm);
		junsbae.executeForm(shrubberyForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}