# include "Cat.hpp"

Cat::Cat(void)
: Animal()
{
	type = "Cat";
	std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat(const Cat& obj)
: Animal()
{
	this->type = obj.type;
	std::cout << "Cat copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& obj)
{
	this->type = obj.type;
	std::cout << "Cat copy assignment operator called." << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}