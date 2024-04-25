#include "Animal.hpp"

Animal::Animal(void)
: type("no type")
{
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(const Animal& obj)
{
	this->type = obj.type;
	std::cout << "Animal copy constructor called." << std::endl;
}

Animal& Animal::operator=(const Animal& obj)
{
	this->type = obj.type;
	std::cout << "Animal copy assignment operator called." << std::endl;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called." << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "no sound" << std::endl;
}

std::string Animal::getType() const
{
	return (type);
}
