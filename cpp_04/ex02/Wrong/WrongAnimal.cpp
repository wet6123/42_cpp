#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
: type("no type")
{
	std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj)
{
	std::cout << "WrongAnimal copy constructor called." << std::endl;
	if (this->type != obj.type)
		this->type = obj.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj)
{
	std::cout << "WrongAnimal copy assignment operator called." << std::endl;
	if (this->type != obj.type)
		this->type = obj.type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called." << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal no sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (type);
}
