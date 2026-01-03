#include "Character.hpp"

/**
 * Default constructor
 */
Character::Character() : name("Player")
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
		this->inventory[i] = NULL;
	for (int i = 0; i < 100; ++i)
		this->inventoryTrash[i] = NULL;
}

/**
 * Parameterized constructor
 * @name: Name of the character
 */
Character::Character(const std::string& name) : name(name)
{
	std::cout << "Character parameterized constructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
		this->inventory[i] = NULL;
	for (int i = 0; i < 100; ++i)
		this->inventoryTrash[i] = NULL;
}

/**
 * Copy constructor
 * @other: Another Character object to copy from
 */
Character::Character(const Character& other) : name(other.name)
{
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
	for (int i = 0; i < 100; ++i)
		this->inventoryTrash[i] = NULL;
}

/**
 * Copy assignment operator
 * @other: Another Character object to assign from
 * Return: Reference to the assigned object
 */
Character& Character::operator=(const Character& other)
{
	std::cout << "Character copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		for (int i = 0; i < 4; ++i)
		{
			if (this->inventory[i])
			{
				delete this->inventory[i];
				this->inventory[i] = NULL;
			}
			if (other.inventory[i])
				this->inventory[i] = other.inventory[i]->clone();
		}
		for (int i = 0; i < 100; ++i)
			this->inventoryTrash[i] = NULL;
	}
	return (*this);
}

/**
 * Destructor
 */
Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		if (this->inventory[i])
			delete this->inventory[i];
	}
	this->clearInventoryTrash();
}

/**
 * Get the name of the character
 * Return: Constant reference to the name string
 */
std::string const & Character::getName() const
{
	return (this->name);
}

/**
 * Equip a materia to the character's inventory
 * @m: Pointer to the AMateria to equip
 */
void Character::equip(AMateria* m)
{
	if (m == NULL)
	{
		std::cout << "Cannot equip NULL materia" << std::endl;
		return;
	}
	for (int i = 0; i < 4; ++i)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			std::cout << "Equipped " << m->getType() << " materia to slot " << i << std::endl;
			return;
		}
	}
	std::cout << "Inventory full, cannot equip materia" << std::endl;
}

/**
 * Unequip a materia from the character's inventory
 * @idx: Index of the inventory slot to unequip
 */
void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Invalid inventory index" << std::endl;
		return;
	}
	if (this->inventory[idx])
	{
		std::cout << "Unequipped " << this->inventory[idx]->getType() << " materia from slot " << idx << std::endl;
		this->addToTrash(this->inventory[idx]);
		this->inventory[idx] = NULL;
	}
	else
		std::cout << "No materia to unequip in slot " << idx << std::endl;
}

/**
 * Use a materia from the character's inventory on a target character
 * @idx: Index of the inventory slot to use
 * @target: The target character
 */
void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Invalid inventory index" << std::endl;
		return;
	}
	if (this->inventory[idx])
		this->inventory[idx]->use(target);
	else
		std::cout << "No materia to use in slot " << idx << std::endl;
}

/**
 * Add a materia to the inventory trash for later cleanup
 * @m: Pointer to the AMateria to add to trash
 */
void Character::addToTrash(AMateria* m)
{
	for (int i = 0; i < 100; ++i)
	{
		if (this->inventoryTrash[i] == NULL)
		{
			this->inventoryTrash[i] = m;
			return;
		}
	}
}

/**
 * Clear the inventory trash, deleting all stored materias
 */
void Character::clearInventoryTrash()
{
	for (int i = 0; i < 100; ++i)
	{
		if (this->inventoryTrash[i])
		{
			delete this->inventoryTrash[i];
			this->inventoryTrash[i] = NULL;
		}
	}
}
