#include "Zombie.hpp"

/**
 * randomChump - Creates and announces a new zombie
 * @name: The name of the new zombie.
 */
void	randomChump( std::string name )
{
	Zombie	zombie;

	zombie.setZombieName(name);
	zombie.announce();
}