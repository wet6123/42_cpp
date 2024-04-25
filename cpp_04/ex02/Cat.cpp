# include "Cat.hpp"

Cat::Cat(void)
: Animal()
{
	type = "Cat";
	brain = new Brain();
	for(int i = 0; i < 100; i++)
	{
		brain->setIdeas(i, "Cat idea" + std::to_string(i));
	}
	std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat(const Cat& obj)
{
	this->type = obj.type;
	delete this->brain;
	this->brain = new Brain();
	for(int i = 0; i < 100; i++)
	{
		this->brain->setIdeas(i, obj.brain->getIdeas(i));
	}
	std::cout << "Cat copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& obj)
{
	this->type = obj.type;
	delete this->brain;
	this->brain = new Brain();
	for(int i = 0; i < 100; i++)
	{
		this->brain->setIdeas(i, obj.brain->getIdeas(i));
	}
	std::cout << "Cat copy assignment operator called." << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	delete brain;
	std::cout << "Cat destructor called." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

Brain* Cat::getBrain(void) const
{
	return (brain);
}
