# include "Dog.hpp"

Dog::Dog(void)
: Animal()
{
	type = "Dog";
	brain = new Brain();
	for(int i = 0; i < 100; i++)
	{
		brain->setIdeas(i, "Dog idea" + std::to_string(i));
	}
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(const Dog& obj)
{
	this->type = obj.type;
	delete this->brain;
	this->brain = new Brain();
	for(int i = 0; i < 100; i++)
	{
		this->brain->setIdeas(i, obj.brain->getIdeas(i));
	}
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& obj)
{
	this->type = obj.type;
	delete this->brain;
	this->brain = new Brain();
	for(int i = 0; i < 100; i++)
	{
		this->brain->setIdeas(i, obj.brain->getIdeas(i));
	}
	std::cout << "Dog copy assignment operator called." << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	delete brain;
	std::cout << "Dog destructor called." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Bowwow" << std::endl;
}

Brain* Dog::getBrain(void) const
{
	return (brain);
}
