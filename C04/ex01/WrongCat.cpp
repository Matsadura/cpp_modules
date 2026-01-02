#include "WrongCat.hpp"

/**
 * Default constructor
 */
WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor called" << std::endl;
}

/**
 * Copy constructor
 * @other: Another WrongCat object to copy from
 */
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

/**
 * Copy assignment operator
 * @other: Another WrongCat object to assign from
 * Return: Reference to the assigned object
 */
WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	return (*this);
}

/**
 * Destructor
 */
WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

/**
 * Make sound
 */
void WrongCat::makeSound() const
{
	std::cout << "Meow (wrongly)" << std::endl;
}