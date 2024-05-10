#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
	{
		Bureaucrat junsbae("junsbae", 1);
		Bureaucrat seongwol("seongwol", 101);
		Form aguform1("AGU form 1", false, 100, 100);
		Form aguform2("AGU form 2", false, 100, 100);
		// Form aguform3("AGU form 2", false, 100, 151);
		std::cout << junsbae << '\n';
		std::cout << seongwol << '\n';
		std::cout << aguform1 << '\n';
		std::cout << aguform2 << '\n';


		std::cout << "\n-------- junsbae sign AGU form 1 --------" << '\n';
		aguform1.beSigned(junsbae);
		std::cout << aguform1 << '\n';
		
		std::cout << "\n-------- seongwol sign AGU form 2 --------" << '\n';
		aguform2.beSigned(seongwol);
		std::cout << aguform2 << '\n';

		std::cout << junsbae << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}