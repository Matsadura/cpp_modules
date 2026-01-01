#include "ScavTrap.hpp"

/**
 * Default Constructors
 */
ScavTrap::ScavTrap( void ): ClapTrap()
{
	this->_name = "ScavTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap Default constructor called.\n";
}

/**
 * Parametreized Constructors
 * @name: Name of the ScavTrap
 */
ScavTrap::ScavTrap( const std::string& name): ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap Parametreized constructor called.\n";
}

/**
 * Copy Constructor
 * @other: ScavTrap to copy from
 */
ScavTrap::ScavTrap( const ScavTrap& other): ClapTrap(other)
{
	std::cout << "ScavTrap Copy constructor called.\n";
	*this = other;
	return ;
}

/**
 * Copy Assignment Operator
 * @other: ScavTrap to copy from
 * Return: Reference to this ScavTrap
 */
ScavTrap& ScavTrap::operator=( const ScavTrap& other )
{
	std::cout << "ScavTrap Copy assignement operator called.\n";
	if (this != &other )
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

/**
 * Destructor
 */
ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap Destructor called.\n";
}

/**
 * attack - Attack function
 * @target: Target to attack
 */
void ScavTrap::attack( const std::string &target )
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << this->_name << " brutally attacks "
			<< target << " causing "
			<< this->_attackDamage 
			<< " points of damage\n";
		this->_energyPoints--;
		return ;
	}

	std::cout << this->_name << " cannot use attack.\n";
}

/**
 * guardGate - special ability
 */
void ScavTrap::guardGate( void )
{
	std::cout << this->_name << " is now in Gate keeper mode\n";
}
