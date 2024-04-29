# include "Dog.hpp"

Dog::Dog(void)
: Animal()
{
	type = "Dog";
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(const Dog& obj)
: Animal()
{
	this->type = obj.type;
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& obj)
{
	this->type = obj.type;
	std::cout << "Dog copy assignment operator called." << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Bowwow" << std::endl;
}
