#include "Ice.hpp"

/**
 * Default constructor
 */
Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}

/**
 * Copy constructor
 * @other: Another Ice object to copy from
 */
Ice::Ice(const Ice& other) : AMateria(other)
{
	std::cout << "Ice copy constructor called" << std::endl;
}

/**
 * Copy assignment operator
 * @other: Another Ice object to assign from
 * Return: Reference to the assigned object
 */
Ice& Ice::operator=(const Ice& other)
{
	std::cout << "Ice copy assignment operator called" << std::endl;
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

/**
 * Destructor
 */
Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

/**
 * Clone the Ice object
 * Return: Pointer to the cloned AMateria object
 */
AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

/**
 * Use the Ice materia on a target character
 * @target: The target character
 */
void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
