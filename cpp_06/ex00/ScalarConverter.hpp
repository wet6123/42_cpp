#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter
{
	private:
		std::string _input;
		ScalarConverter(void);
	public:
		ScalarConverter(std::string input);
		ScalarConverter(const ScalarConverter& obj);
		ScalarConverter& operator=(const ScalarConverter& obj);
		~ScalarConverter(void);

		void convert();
};

#endif