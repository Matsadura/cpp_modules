#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void )
{
}

ClapTrap::ClapTrap( const std::string& name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
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

void ClapTrap::attack( const std::string &target )
{
	if (this->_energyPoints > 0)
	{
		std::cout << this->_name << "attacks " << target << "and deals " << this->_attackDamage << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << this->_name << "has 0 energy points\n";
}