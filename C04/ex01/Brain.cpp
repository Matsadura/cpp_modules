#include "Brain.hpp"

/**
 * Default constructor
 */
Brain::Brain() 
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; ++i) 
		this->ideas[i] = "Idea";
}

/**
 * Copy constructor
 * @other: Another Brain object to copy from
 */
Brain::Brain(const Brain& other) 
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; ++i) 
		this->ideas[i] = other.ideas[i];
}

/**
 * Copy assignment operator
 * @other: Another Brain object to assign from
 * Return: Reference to the assigned object
 */
Brain& Brain::operator=(const Brain& other) 
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &other) 
	{
		for (int i = 0; i < 100; ++i) 
			this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

/**
 * Destructor
 */
Brain::~Brain() 
{
	std::cout << "Brain destructor called" << std::endl;
}