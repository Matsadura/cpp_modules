#include "ClapTrap.hpp"

/**
 * Default Constructors
 */
ClapTrap::ClapTrap( void ): _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor called.\n";
}

/**
 * Parametreized Constructors
 * @name: Name of the ClapTrap
 */
ClapTrap::ClapTrap( const std::string& name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Parametreized constructor called.\n";
}

/**
 * Copy Constructor
 * @other: ClapTrap to copy from
 */
ClapTrap::ClapTrap( const ClapTrap& other)
{
	std::cout << "Copy constructor called.\n";
	*this = other;
	return ;
}

/**
 * Copy Assignment Operator
 * @other: ClapTrap to copy from
 * Return: Reference to this ClapTrap
 */
ClapTrap& ClapTrap::operator=( const ClapTrap& other )
{
	std::cout << "Copy assignement operator called.\n";
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
ClapTrap::~ClapTrap( void )
{
	std::cout << "Destructor called.\n";
}

/**
 * attack - Attack function
 * @target: Target to attack
 */
void ClapTrap::attack( const std::string &target )
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << this->_name << " attacks "
			<< target << " causing "
			<< this->_attackDamage 
			<< " points of damage\n";
		this->_energyPoints--;
		return ;
	}

	std::cout << this->_name << " cannot use attack.\n";
}

/**
 * beRepaired - Repair function
 * @amount: Amount of hit points to restore
 */
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_hitPoints += amount;
		std::cout << this->_name << " repairs itself and restores "
			<< amount << " for a total of "
			<< this->_hitPoints 
			<< " hit points.\n";
		this->_energyPoints--;
		return ;	
	}

	std::cout << this->_name << " cannot use repair.\n";
}

/**
 * takeDamage - Damage function
 * @amount: Amount of damage to take
 */
void ClapTrap::takeDamage( unsigned int amount )
{
	if (this->_hitPoints <= 0)
		std::cout << this->_name << " is already dead\n";
	else
	{
		if ((int)amount >= this->_hitPoints)
			this->_hitPoints = 0;
		else
			this->_hitPoints -= amount;

		std::cout << this->_name << " takes "
			<< amount << " of damage and now has "
			<< this->_hitPoints << " hit points\n";
	}
}
