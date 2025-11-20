#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon( std::string name )
{
	this->_type = name;
}

Weapon::~Weapon()
{
}

void	Weapon::setType( std::string type )
{
	this->_type = type;
}

std::string const & Weapon::getType( void ) const
{
	return (this->_type);
} 

