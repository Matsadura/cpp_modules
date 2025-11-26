/**
 * Zombie.cpp
 * Implementation of the Zombie Class.
 * 
 */
#include "Zombie.hpp"

/**
 * Zombie - Class constructor
 */
Zombie::Zombie( void )
{	
}

Zombie::Zombie( std::string name )
{
	this->_name = name;
}

/**
 * Zombie - Class destructor
 */
Zombie::~Zombie( void )
{
	std::cout << this->getZombieName() + ": I have been destroyed\n";
}

/**
 * setZombieName - Setter for name attribute
 * @name: name to set.
 */
void Zombie::setZombieName( std::string name )
{
	this->_name = name;
}

/**
 * getZombieName - Getter for name attribute
 */
std::string Zombie::getZombieName( void ) const
{
	return (this->_name);
}

/**
 * announce - Declares the name of newly spawn zombie
 */
void Zombie::announce( void )
{
	std::cout << this->getZombieName() << ": BraiiiiiiinnnzzzZ...\n";
}
