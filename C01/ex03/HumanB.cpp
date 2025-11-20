#include "HumanB.hpp"

HumanB::HumanB( std::string name )
{
	this->_name = name;
	this->_weapon = NULL;
}

HumanB::~HumanB( void )
{
}

void	HumanB::setWeapon( Weapon& weapon )
{
	this->_weapon = &weapon;
}

Weapon* HumanB::getWeapon( void ) const
{
	return (this->_weapon);
}

void HumanB::attack( void )
{
	std::cout
		<< "HumanB attack with their "
		<< (*this->getWeapon()).getType()
		<< "\n";
}