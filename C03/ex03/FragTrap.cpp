#include "FragTrap.hpp"

/**
 * Default Constructors
 */
FragTrap::FragTrap( void ): ClapTrap()
{
	this->_name = "FragTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap Default constructor called.\n";
}

/**
 * Parametreized Constructors
 * @name: Name of the FragTrap
 */
FragTrap::FragTrap( const std::string& name): ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap Parametreized constructor called.\n";
}

/**
 * Copy Constructor
 * @other: FragTrap to copy from
 */
FragTrap::FragTrap( const FragTrap& other): ClapTrap(other)
{
	std::cout << "FragTrap Copy constructor called.\n";
	*this = other;
	return ;
}

/**
 * Copy Assignment Operator
 * @other: FragTrap to copy from
 * Return: Reference to this FragTrap
 */
FragTrap& FragTrap::operator=( const FragTrap& other )
{
	std::cout << "FragTrap Copy assignement operator called.\n";
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
FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap Destructor called.\n";
}

/**
 * attack - Attack function
 * @target: Target to attack
 */
void FragTrap::attack( const std::string &target )
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
 * highFiveGuys - special ability
 */
void FragTrap::highFiveGuys( void )
{
	std::cout << this->_name << " is requesting a high five\n";
}
