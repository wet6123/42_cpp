#include "Zombie.hpp"

int main(void)
{
	int N;
	N = 10;

	Zombie* zombies = zombieHorde(N, "junsbae");

	for(int i = 0; i < N; i++)
	{
		zombies[i].announce();
	}

	delete[] zombies;

	return (0);
}