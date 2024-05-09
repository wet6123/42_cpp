#include "Bureaucrat.hpp"

int main()
{
    try
	{
		// instance init test
		try
		{
			Bureaucrat wrong("wrong", 151);	
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		

		// increment, decrement test
		Bureaucrat test("test", 150);
		std::cout << test.getName() << " " << test.getGrade() << '\n';

 		test.incrementGrade();
		std::cout << test.getName() << " " << test.getGrade() << '\n';
		
		// test.decrementGrade();
		test.decrementGrade();
		std::cout << test.getName() << " " << test.getGrade() << '\n';

		// --------------------------------------------------------------
		Bureaucrat test2("test2", 1);
		std::cout << test2.getName() << " " << test2.getGrade() << '\n';

 		test2.decrementGrade();
		std::cout << test2.getName() << " " << test2.getGrade() << '\n';

		// test2.incrementGrade();
		test2.incrementGrade();
		std::cout << test2.getName() << " " << test2.getGrade() << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}