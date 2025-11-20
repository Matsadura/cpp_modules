#include "HumanA.hpp"

/**
 * HumanA - Class constructor
 * @name: HumanA's name
 * @weapon: Referance to weapon
 */
HumanA::HumanA( std::string name, Weapon& weapon ) : _name(name), _weapon(weapon)
{
}

/**
 * Class destructor
 */
HumanA::~HumanA( void )
{
}

/**
 * getWeapon - Getter for weapon attribute
 * Return: Weapon
 */
Weapon const& HumanA::getWeapon( void ) const
{
	return (this->_weapon);
}

/**
 * attack - Prints attack statement
 */
void HumanA::attack( void )
{
	std::cout
		<< "HumanA attack with their "
		<< this->getWeapon().getType()
		<< "\n";
}