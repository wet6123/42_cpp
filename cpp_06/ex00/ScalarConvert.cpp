#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(std::string input)
: _input(input)
{}

ScalarConverter::ScalarConverter(const ScalarConverter& obj)
{
	if (this != &obj)
		*this = obj;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj)
{
	if (this != &obj)
		_input = obj._input;
	return *this;
}

ScalarConverter::~ScalarConverter(void)
{}

void ScalarConverter::convert()
{
	
}