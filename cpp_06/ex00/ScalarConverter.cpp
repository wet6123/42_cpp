#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{}

ScalarConverter::~ScalarConverter(void)
{}

void ScalarConverter::convert(const std::string& str)
{
	double value;
	char* end;
	end = NULL;

	try
	{
		value = std::strtod(str.c_str(), &end);
		// throw exception
		if (str.length() == 1 && !std::isdigit(str[0]))
		{
			// char
			value = static_cast<double>(str[0]);
		}
		else if (std::strcmp(str.c_str(), "nan") &&
		std::strcmp(str.c_str(), "nanf") &&
		std::strcmp(str.c_str(), "inf") &&
		std::strcmp(str.c_str(), "inff") &&
		std::strcmp(str.c_str(), "+inf") &&
		std::strcmp(str.c_str(), "+inff") &&
		std::strcmp(str.c_str(), "-inf") &&
		std::strcmp(str.c_str(), "-inff"))
		{
			if (
				(*end && std::strcmp(end, "f")) ||
				(str[0] != '+' && str[0] != '-' && !std::isdigit(str[0])) ||
				((str[0] == '+' || str[0] == '-') && !std::isdigit(str[1])) ||
				(str != end && *(end - 1) == '.'))
			{	
				// exception
				throw std::bad_alloc();
			}
		}
	}
	catch (std::exception &e)
	{
		std::cout << "convert failed." << std::endl;
		return ;
	}
	
	// char
	std::cout << "char: ";
	if (std::isinf(value) || std::isnan(value))
		std::cout << "impossible" << std::endl;
	else if (std::isprint(static_cast<char>(value)))
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	
	// inf
	std::cout << "int: ";
	if (std::isinf(value) || std::isnan(value) || value > INT_MAX || value < INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
	
	// float
	std::cout << "float: ";
	if (std::isinf(value) || std::isnan(value))
		std::cout << static_cast<float>(value) << "f" << std::endl;
	else
	{
		std::cout << static_cast<float>(value);
		if (static_cast<float>(value) == static_cast<int>(value))
			std::cout << ".0";
		std::cout << "f" << std::endl;
	
	}

	// double
	std::cout << "double: ";
	if (std::isinf(value) || std::isnan(value))
		std::cout << value << std::endl;
	else
	{
		std::cout << value;
		if (value == static_cast<int>(value))
			std::cout << ".0";
		std::cout << std::endl;
	}
}