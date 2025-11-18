#include "Zombie.hpp"

/**
 * newZombie - Creates and names a new zombie
 * @name: The name of new zombie
 * Return: Zombie object.
 */
Zombie*	newZombie( std::string name )
{
	Zombie* dead_body;

	dead_body = new Zombie();
	dead_body->setZombieName(name);
	dead_body->announce();
	return (dead_body);
}