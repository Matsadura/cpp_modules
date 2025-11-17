#include "Zombie.hpp"

Zombie::Zombie( void )
{	
}

Zombie::~Zombie( void )
{
}

void Zombie::setZombieName( std::string name )
{
	this->_name = name;
}

std::string Zombie::getZombieName( void ) const
{
	return (this->_name);
}

void Zombie::announce( void )
{
	std::cout << this->getZombieName() << ": BraiiiiiiinnnzzzZ...\n";
}
