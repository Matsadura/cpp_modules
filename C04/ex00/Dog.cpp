#include "Dog.hpp"

/**
 * Default constructor
 */
Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
}

/**
 * Copy constructor
 * @other: Another Dog object to copy from
 */
Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

/**
 * Copy assignment operator
 * @other: Another Dog object to assign from
 * Return: Reference to the assigned object
 */
Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return (*this);
}

/**
 * Destructor
 */
Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

/**
 * Make sound
 */
void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}