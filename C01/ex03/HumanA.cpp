#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA( void )
{
}

Weapon const& HumanA::getWeapon( void ) const
{
	return (this->_weapon);
}

void HumanA::attack( void )
{
	std::cout
		<< "HumanA attack with their "
		<< this->getWeapon().getType()
		<< "\n";
}