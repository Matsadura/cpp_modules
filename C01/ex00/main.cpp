#include "Zombie.hpp"

int main(void)
{
	Zombie* zombie;

	zombie = newZombie("Zombie 1");
	randomChump("Random Zombie");
	delete zombie;
	return (0);
}