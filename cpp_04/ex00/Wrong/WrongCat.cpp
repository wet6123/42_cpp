# include "WrongCat.hpp"

WrongCat::WrongCat(void)
: WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj)
: WrongAnimal()
{
	this->type = obj.type;
	std::cout << "WrongCat copy constructor called." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& obj)
{
	if (this->type != obj.type)
		this->type = obj.type;
	std::cout << "WrongCat copy assignment operator called." << std::endl;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called." << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat Meow" << std::endl;
}