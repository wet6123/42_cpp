#include <iostream>

int main(void)
{
	std::string		str;
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	str = "HI THIS IS BRAIN";

	std::cout << "str		memory address : " << &str << "\n";
	std::cout << "stringPTR	memory address : " << stringPTR << "\n";
	std::cout << "stringREF	memory address : " << &stringREF << "\n";

	std::cout << "str		value : " << str << "\n";
	std::cout << "stringPTR	value : " << *stringPTR << "\n";
	std::cout << "stringREF	value : " << stringREF << "\n";
	return (0);
}