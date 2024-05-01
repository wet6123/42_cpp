# include "Dog.hpp"

Dog::Dog(void)
: Animal()
{
	std::cout << "Dog default constructor called." << std::endl;
	type = "Dog";
	brain = new Brain();
	for(int i = 0; i < 100; i++)
	{
		std::stringstream ss;
		ss << "Dog idea" << i;
		brain->setIdeas(i, ss.str());
	}
}

Dog::Dog(const Dog& obj)
: Animal()
{
	std::cout << "Dog copy constructor called." << std::endl;
	if (this == &obj)
		return ;
	this->type = obj.type;
	this->brain = new Brain();
	for(int i = 0; i < 100; i++)
	{
		this->brain->setIdeas(i, obj.brain->getIdeas(i));
	}
}

Dog& Dog::operator=(const Dog& obj)
{
	std::cout << "Dog copy assignment operator called." << std::endl;
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

Dog::~Dog(void)
{
	std::cout << "Dog destructor called." << std::endl;
	delete brain;
}

void Dog::makeSound() const
{
	std::cout << "Bowwow" << std::endl;
}

Brain* Dog::getBrain(void) const
{
	return (brain);
}
