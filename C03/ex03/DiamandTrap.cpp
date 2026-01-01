#include "DiamandTrap.hpp"

/**
 * Default Constructors
 */
DiamandTrap::DiamandTrap( void ): ClapTrap(), FragTrap(), ScavTrap()
{
	this->_name = "DiamandTrap";
	ClapTrap::_name = this->_name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = 30;
	std::cout << "DiamandTrap Default constructor called.\n";
}

/**
 * Parametreized Constructors
 * @name: Name of the DiamandTrap
 */
DiamandTrap::DiamandTrap( const std::string& name): ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = 30;

	std::cout << "DiamandTrap Parametreized constructor called.\n";
}

/**
 * Copy Constructor
 * @other: DiamandTrap to copy from
 */
DiamandTrap::DiamandTrap( const DiamandTrap& other): ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	std::cout << "DiamandTrap Copy constructor called.\n";
	*this = other;
	return ;
}

/**
 * Copy Assignment Operator
 * @other: DiamandTrap to copy from
 * Return: Reference to this DiamandTrap
 */
DiamandTrap& DiamandTrap::operator=( const DiamandTrap& other )
{
	std::cout << "DiamandTrap Copy assignement operator called.\n";
	if (this != &other )
	{
		this->_name = other._name;
		ClapTrap::_name = other.ClapTrap::_name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

/**
 * Destructor
 */
DiamandTrap::~DiamandTrap( void )
{
	std::cout << "DiamandTrap Destructor called.\n";
}

/**
 * attack - Attack function
 * @target: Target to attack
 */
void DiamandTrap::attack( const std::string &target )
{
	if (this->_energyPoints <= 0)
	{
		std::cout << this->_name << " has no energy points left to attack.\n";
		return ;
	}
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_name << " has no hit points left to attack.\n";
		return ;
	}
	ScavTrap::attack(target);
}

/**
 * whoAmI - Display the DiamandTrap and ClapTrap names
 */
void DiamandTrap::whoAmI( void )
{
	std::cout << "DiamandTrap name: " << this->_name << ", ClapTrap name: " << ClapTrap::_name << "\n";
}

void DiamandTrap::getStats( void ) const
{
	std::cout << "DiamandTrap Stats -- Name: " << this->_name
			  << ", Hit Points: " << this->_hitPoints
			  << ", Energy Points: " << this->_energyPoints
			  << ", Attack Damage: " << this->_attackDamage << std::endl;
}