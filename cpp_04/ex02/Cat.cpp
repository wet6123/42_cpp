# include "Cat.hpp"

Cat::Cat(void)
: Animal()
{
	std::cout << "Cat default constructor called." << std::endl;
	type = "Cat";
	brain = new Brain();
	for(int i = 0; i < 100; i++)
	{
		std::stringstream ss;
		ss << "Cat idea" << i;
		brain->setIdeas(i, ss.str());
	}
}

Cat::Cat(const Cat& obj)
: Animal()
{
	std::cout << "Cat copy constructor called." << std::endl;
	if (this == &obj)
		return ;
	this->type = obj.type;
	this->brain = new Brain();
	for(int i = 0; i < 100; i++)
	{
		this->brain->setIdeas(i, obj.brain->getIdeas(i));
	}
}

Cat& Cat::operator=(const Cat& obj)
{
	std::cout << "Cat copy assignment operator called." << std::endl;
	if (this == &obj)
		return (*this);
	this->type = obj.type;
	delete this->brain;
	this->brain = new Brain();
	for(int i = 0; i < 100; i++)
	{
		this->brain->setIdeas(i, obj.brain->getIdeas(i));
	}
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called." << std::endl;
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

Brain* Cat::getBrain(void) const
{
	return (brain);
}
