#include "Zombie.hpp"

int main(void)
{
	Zombie* zombie;

	int n = 5;
	zombie = zombieHorde(n, "Zombies");
	for (int i = 0; i < n; i++)
		zombie[i].announce();
	delete[] zombie;
	return (0);
}