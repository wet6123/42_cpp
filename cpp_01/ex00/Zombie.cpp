#include "Zombie.hpp"

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