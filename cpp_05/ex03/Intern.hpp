#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"

class Intern
{
	private:
		Intern(const Intern& obj);
		Intern& operator=(const Intern& obj);
	public:
		Intern(void);
		~Intern(void);

		AForm& makeForm(const std::string& formName, const std::string& target);
};

#endif