#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void )
{
}

ClapTrap::ClapTrap(
			const std::string& name,
			const unsigned int& hp,
			const unsigned int& ep,
			const unsigned int& ad
			) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
}

ClapTrap::ClapTrap( const ClapTrap& other)
{
	*this = other;
	return ;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& other )
{
	if (this != &other )
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}

	return (*this);
}

ClapTrap::~ClapTrap( void )
{
}
