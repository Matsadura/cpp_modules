#include "MateriaSource.hpp"

/**
 * Default constructor
 */
MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
		this->materia[i] = NULL;
}

/**
 * Copy constructor
 * @other: Another MateriaSource object to copy from
 */
MateriaSource::MateriaSource(const MateriaSource& other)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		if (other.materia[i])
			this->materia[i] = other.materia[i]->clone();
		else
			this->materia[i] = NULL;
	}
}

/**
 * Copy assignment operator
 * @other: Another MateriaSource object to assign from
 * Return: Reference to the assigned object
 */
MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	std::cout << "MateriaSource copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (this->materia[i])
			{
				delete this->materia[i];
				this->materia[i] = NULL;
			}
			if (other.materia[i])
				this->materia[i] = other.materia[i]->clone();
		}
	}
	return (*this);
}

/**
 * Destructor
 */
MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		if (this->materia[i])
			delete this->materia[i];
	}
}

/**
 * Learn a new materia
 * @m: Pointer to the AMateria to learn
 */
void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->materia[i] == NULL)
		{
			this->materia[i] = m;
			std::cout << "Learned " << m->getType() << " materia in slot " << i << std::endl;
			return;
		}
	}
	std::cout << "MateriaSource is full, cannot learn more materia" << std::endl;
	if (m)
		delete m;
}

/**
 * Create a materia of the given type
 * @type: Type of the materia to create
 * Return: Pointer to the created AMateria object, or NULL if not found
 */
AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->materia[i] && this->materia[i]->getType() == type)
		{
			std::cout << "Created " << type << " materia from slot " << i << std::endl;
			return (this->materia[i]->clone());
		}
	}
	std::cout << "Materia of type " << type << " not found" << std::endl;
	return (NULL);
}