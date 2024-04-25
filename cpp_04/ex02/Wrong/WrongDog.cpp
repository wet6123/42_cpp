# include "WrongDog.hpp"

WrongDog::WrongDog(void)
: Animal()
{
	type = "WrongDog";
	std::cout << "WrongDog default constructor called." << std::endl;
}

WrongDog::WrongDog(const WrongDog& obj)
{
	this->type = obj.type;
	std::cout << "WrongDog copy constructor called." << std::endl;
}

WrongDog& WrongDog::operator=(const WrongDog& obj)
{
	this->type = obj.type;
	std::cout << "WrongDog copy assignment operator called." << std::endl;
	return (*this);
}

WrongDog::~WrongDog(void)
{
	std::cout << "WrongDog destructor called." << std::endl;
}

void WrongDog::makeSound() const
{
	std::cout << "WrongDog Bowwow" << std::endl;
}
