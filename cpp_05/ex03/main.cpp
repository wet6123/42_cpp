#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    try
	{
		Bureaucrat junsbae("junsbae", 1);
		Intern intern;
		AForm* shrubberyForm = intern.makeForm("shrubbery creation", "home");
		AForm* robotomyForm = intern.makeForm("robotomy request", "polabear");
		AForm* pardonForm = intern.makeForm("presidential pardon", "seongwol");
		std::cout << "\n";

		// ShrubberyCreationForm
		junsbae.signForm(*shrubberyForm);
		junsbae.executeForm(*shrubberyForm);
		std::cout << "\n";

		// PresidentialPardonForm
		junsbae.signForm(*pardonForm);
		junsbae.executeForm(*pardonForm);
		std::cout << "\n";

		// RobotomyRequestForm
		junsbae.signForm(*robotomyForm);
		junsbae.executeForm(*robotomyForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}