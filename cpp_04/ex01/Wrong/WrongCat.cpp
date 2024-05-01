# include "WrongCat.hpp"

WrongCat::WrongCat(void)
: WrongAnimal()
{
	std::cout << "WrongCat default constructor called." << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& obj)
: WrongAnimal()
{
	std::cout << "WrongCat copy constructor called." << std::endl;
	if (this->type != obj.type)
		this->type = obj.type;
}

WrongCat& WrongCat::operator=(const WrongCat& obj)
{
	std::cout << "WrongCat copy assignment operator called." << std::endl;
	if (this->type != obj.type)
		this->type = obj.type;
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