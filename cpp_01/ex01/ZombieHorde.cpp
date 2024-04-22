#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie* zombies = new Zombie[N];

	for(int i = 0; i < N; i++)
	{
		// std::string tmp;
		// tmp = name + " " + std::to_string(i);
		// zombies[i].setName(tmp);
		zombies[i].setName(name);
	}

	return (zombies);
}
