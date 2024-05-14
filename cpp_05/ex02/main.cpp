#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    try
	{
		Bureaucrat polarbear("polarbear", 1);
		Bureaucrat seongwol("seongwol", 50);
		Bureaucrat junsbae("junsbae", 140);

		// Required grades: sign 145, exec 137
		ShrubberyCreationForm shrubberyForm("test1");
		// Required grades: sign 72, exec 45
		RobotomyRequestForm robotomyForm("test2");
		// Required grades: sign 25, exec 5
		PresidentialPardonForm presidentialForm("test3");

		// ShrubberyCreationForm
		junsbae.signForm(shrubberyForm);
		seongwol.signForm(shrubberyForm);
		junsbae.executeForm(shrubberyForm);
		seongwol.executeForm(shrubberyForm);
		std::cout << "\n";

		// RobotomyRequestForm
		junsbae.signForm(robotomyForm);
		seongwol.signForm(robotomyForm);
		junsbae.executeForm(robotomyForm);
		polarbear.executeForm(robotomyForm);
		std::cout << "\n";

		// PresidentialPardonForm
		junsbae.signForm(presidentialForm);
		// polarbear.signForm(presidentialForm);
		junsbae.executeForm(presidentialForm);
		polarbear.executeForm(presidentialForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}