#include "WrongAnimal.hpp"

/**
 * Default constructor
 */
WrongAnimal::WrongAnimal() 
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
	this->type = "WrongAnimal";
}

/**
 * Parameterized constructor
 * @type: Type of the wrong animal
 */
WrongAnimal::WrongAnimal(const std::string& type) : type(type) 
{
	std::cout << "WrongAnimal parameterized constructor called" << std::endl;
}

/**
 * Copy constructor
 * @other: Another WrongAnimal object to copy from
 */
WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) 
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

/**
 * Copy assignment operator
 * @other: Another WrongAnimal object to assign from
 * Return: Reference to the assigned object
 */
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) 
{
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &other) 
	{
		this->type = other.type;
	}
	return (*this);
}

/**
 * Destructor
 */
WrongAnimal::~WrongAnimal() 
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

/**
 * Get type
 * Return: Type of the wrong animal
 */
std::string WrongAnimal::getType() const 
{
	return (this->type);
}

/**
 * Make sound
 */
void WrongAnimal::makeSound() const 
{
	std::cout << "Some wrong animal sound" << std::endl;
}
