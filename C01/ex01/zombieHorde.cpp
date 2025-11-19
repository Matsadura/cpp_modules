#include "Zombie.hpp"

/**
 * zombieHordes - Creates a horde of zombies
 * @n: The number of zombies
 * @name: The name of the zombies
 * Return: Pointer to the first zombie
 */
Zombie* zombieHorde(int n, std::string name)
{
	if ( n <= 0 )
	{
		std::cerr << "Error: N cannot be less than or equal to 0\n";
		return (NULL);
	}

	Zombie* zombies = new Zombie[n];

	for (int i = 0; i < n; i++)
		zombies[i].setZombieName(name);
	return (zombies);
}