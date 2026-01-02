#include "Cat.hpp"

/**
 * Default constructor
 */
Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	this->brain = new Brain();
}

/**
 * Copy constructor
 * @other: Another Cat object to copy from
 */
Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = new Brain(*(other.brain));
}


/**
 * Copy assignment operator
 * @other: Another Cat object to assign from
 * Return: Reference to the assigned object
 */
Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		*(this->brain) = *(other.brain);
	}
	return (*this);
}

/**
 * Destructor
 */
Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

/**
 * Make sound
 */
void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}