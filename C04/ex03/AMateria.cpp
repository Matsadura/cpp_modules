#include "AMateria.hpp"

/**
 * Default constructor
 */
AMateria::AMateria() : type("default")
{
	std::cout << "AMateria default constructor called" << std::endl;
}

/**
 * Parameterized constructor
 * @type: Type of the materia
 */
AMateria::AMateria(std::string const & type) : type(type)
{
	std::cout << "AMateria parameterized constructor called" << std::endl;
}

/**
 * Copy constructor
 * @other: Another AMateria object to copy from
 */
AMateria::AMateria(const AMateria& other) : type(other.type)
{
	std::cout << "AMateria copy constructor called" << std::endl;
}

/**
 * Copy assignment operator
 * @other: Another AMateria object to assign from
 * Return: Reference to the assigned object
 */
AMateria& AMateria::operator=(const AMateria& other)
{
	std::cout << "AMateria copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

/**
 * Destructor
 */
AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

/**
 * Get the type of the materia
 * Return: Constant reference to the type string
 */
std::string const & AMateria::getType() const
{
	return (this->type);
}

/**
 * Use the materia on a target character
 * @target: The target character
 */
void AMateria::use(ICharacter& target)
{
	(void)target;
}