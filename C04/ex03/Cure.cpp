#include "Cure.hpp"

/**
 * Default constructor
 */
Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

/**
 * Copy constructor
 * @other: Another Cure object to copy from
 */
Cure::Cure(const Cure& other) : AMateria(other)
{
	std::cout << "Cure copy constructor called" << std::endl;
}

/**
 * Copy assignment operator
 * @other: Another Cure object to assign from
 * Return: Reference to the assigned object
 */
Cure& Cure::operator=(const Cure& other)
{
	std::cout << "Cure copy assignment operator called" << std::endl;
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

/**
 * Destructor
 */
Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

/**
 * Clone the Cure object
 * Return: Pointer to the cloned AMateria object
 */
AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

/**
 * Use the Cure materia on a target character
 * @target: The target character
 */
void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
