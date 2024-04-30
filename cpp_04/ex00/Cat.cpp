# include "Cat.hpp"

Cat::Cat(void)
: Animal()
{
	std::cout << "Cat default constructor called." << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat& obj)
: Animal()
{
	std::cout << "Cat copy constructor called." << std::endl;
	if (this == &obj)
		return ;
	this->type = obj.type;
}

Cat& Cat::operator=(const Cat& obj)
{
	std::cout << "Cat copy assignment operator called." << std::endl;
	if (this == &obj)
		return (*this);
	this->type = obj.type;
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