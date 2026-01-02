#include "Animal.hpp"

/**
 * Default constructor
 */
Animal::Animal() 
{
	std::cout << "Animal default constructor called" << std::endl;
	this->type = "Animal";
}

/**
 * Parameterized constructor
 * @type: Type of the animal
 */
Animal::Animal(const std::string& type) : type(type) 
{
	std::cout << "Animal parameterized constructor called" << std::endl;
}

/**
 * Copy constructor
 * @other: Another Animal object to copy from
 */
Animal::Animal(const Animal& other) : type(other.type) 
{
	std::cout << "Animal copy constructor called" << std::endl;
}

/**
 * Copy assignment operator
 * @other: Another Animal object to assign from
 * Return: Reference to the assigned object
 */
Animal& Animal::operator=(const Animal& other) 
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &other) 
	{
		this->type = other.type;
	}
	return (*this);
}

/**
 * Destructor
 */
Animal::~Animal() 
{
	std::cout << "Animal destructor called" << std::endl;
}

/**
 * Get type
 * Return: Type of the animal
 */
std::string Animal::getType() const 
{
	return (this->type);
}

/**
 * Make sound
 */
void Animal::makeSound() const 
{
	std::cout << "Animal sound" << std::endl;
}
