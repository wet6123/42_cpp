#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie* zombies = new Zombie[N];

	for(int i = 0; i < N; i++)
	{
		// std::string tmp;
		// char num = '0' + i;
		// tmp = name + " " + num;
		// zombies[i].setName(tmp);
		zombies[i].setName(name);
	}

	return (zombies);
}
