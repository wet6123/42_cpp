#include "Zombie.hpp"

Zombie::Zombie(void)
{}

Zombie::Zombie(std::string name)
: name(name)
{}

Zombie::~Zombie(void)
{
	std::cout << name << " died\n";
}

void Zombie::announce(void)
{
	// introduce
	std::cout << name << " : BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(const std::string name)
{
	this->name = name;
}
