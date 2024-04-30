# include "Dog.hpp"

Dog::Dog(void)
: Animal()
{
	std::cout << "Dog default constructor called." << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog& obj)
: Animal()
{
	std::cout << "Dog copy constructor called." << std::endl;
	if (this == &obj)
		return ;
	this->type = obj.type;
}

Dog& Dog::operator=(const Dog& obj)
{
	std::cout << "Dog copy assignment operator called." << std::endl;
	if (this == &obj)
		return (*this);
	this->type = obj.type;
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
