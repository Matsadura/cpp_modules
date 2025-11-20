#include "HumanB.hpp"

/**
 * HumanB - Class constactor
 * @name: Human's name
 */
HumanB::HumanB( std::string name )
{
	this->_name = name;
	this->_weapon = NULL;
}

/**
 * Class destructor
 */
HumanB::~HumanB( void )
{
}

/**
 * setWeapon - Setter for weapon attribute
 * @weapon: Reference to weapon
 */
void	HumanB::setWeapon( Weapon& weapon )
{
	this->_weapon = &weapon;
}

/**
 * getWeapon - Getter for weapon
 * Return: Pointer to weapon object
 */
Weapon* HumanB::getWeapon( void ) const
{
	return (this->_weapon);
}

/**
 * attack - Prints attack statement
 */
void HumanB::attack( void )
{
	std::cout
		<< "HumanB attack with their "
		<< (*this->getWeapon()).getType()
		<< "\n";
}