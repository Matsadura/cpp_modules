/**
 * PhoneBook.cpp
 * Implementation of the PhoneBook class.
 * This class manages a collection of contacts.
 * It allows adding, retrieving, and displaying contacts.
 */
#include "PhoneBook.hpp"

int PhoneBook::max_contacts = 8;

/**
 * PhoneBook - Class constructor
 */
PhoneBook::PhoneBook(void)
{
    this->_nbContacts = 0;
    this->_currentIndex = 0;
}

/**
 * PhoneBook - Class destructor
 */
PhoneBook::~PhoneBook(void)
{
}

/**
 * getNbContacts - Getter for number of contacts
 * return: Number of contacts in the phonebook
 */
int	PhoneBook::getNbContacts(void) const
{
	return (this->_nbContacts);
}

/**
 * setNbContacts - Setter for number of contacts
 * @n: Number of contacts to set
 */
void	PhoneBook::setNbContacts(int n)
{
	this->_nbContacts = n;
}

/**
 * getCurrentIndex - Getter for current index
 * return: Current index in the phonebook
 */
int	PhoneBook::getCurrentIndex(void) const
{
	return (this->_currentIndex);
}

/**
 * setCurrentIndex - Setter for current index
 * @n: Current index to set
 */
void	PhoneBook::setCurrentIndex(int n)
{
	this->_currentIndex = n;
}

/**
 * getContact - Getter for contact at index
 * @index: Index of the contact to get
 * return: Contact at the specified index
 */
Contact PhoneBook::getContact(int index) const
{
    if (index < 0 || index >= this->getNbContacts())
        return Contact();
    return this->_contacts[index];
}

/**
 * setContact - Setter for contacts
 * @index: Index of contact
 * @contact: Contact object
 */
void	PhoneBook::setContact(int index, Contact contact)
{
	this->_contacts[index] = contact;
}

/**
 * formatField - Truncuates a long string
 * @field: The string to truncuate
 * Return: The truncuated result
 */
std::string PhoneBook::formatField(const std::string& field) const
{
	if (field.length() > 10)
		return (field.substr(0, 9) + ".");
	return (field);
}

/**
 * searchContacts - Displays all contacts in the phonebook and specific one
 */
void    PhoneBook::searchContacts(void) const
{
    int i;
	
	std::cout << std::setfill(' ') << std::setw(10) << "index" << "|";
	std::cout << std::setfill(' ') << std::setw(10) << "First name" << "|";
	std::cout << std::setfill(' ') << std::setw(10) << "Last name" << "|";
	std::cout << std::setfill(' ') << std::setw(10) << "Nickname" << std::endl;
    for (i = 0; i < this->getNbContacts(); i++)
    {
		Contact contact = getContact(i);
		std::cout << std::setfill(' ') << std::setw(10) << i << "|";
        std::cout << std::setfill(' ') << std::setw(10) << formatField(contact.getFirstName()) << "|";
		std::cout << std::setfill(' ') << std::setw(10) << formatField(contact.getLastName()) << "|";
		std::cout << std::setfill(' ') << std::setw(10) << formatField(contact.getNickname()) << std::endl;
    }
	displaySingleContact();
}

/**
 * displaySignleContact - Displays a sigle contact based on index
 */
void	PhoneBook::displaySingleContact(void) const
{
	std::string	index;
	int	i;
	Contact contact;

	std::cout << "SEARCH: Enter index: ", std::getline(std::cin, index);
	if (std::cin.fail() || index.length() > 1 || !isdigit(index[0]))
	{
		std::cout << "Error: Invalid index!" << std::endl;
		return ;
	}
	i = std::atoi(index.c_str());
	if (i < 0 || i >= this->getNbContacts())
	{
		std::cout << "Error: No contact found!" << std::endl;
		return ;
	}
	contact = this->_contacts[i];
	std::cout << "First name: " << contact.getFirstName() << std::endl \
		<< "Last name: " << contact.getLastName() << std::endl \
		<< "Nickname: " << contact.getNickname() << std::endl \
		<< "Phone number: " << contact.getPhoneNumber() << std::endl \
		<< "Secret: " << contact.getSecret() << std::endl;
}

/**
 * addContact - Adds a new contact to the phonebook
 */
void PhoneBook::addContact(void)
{
    std::string first_name, last_name, nickname, phone_number, secret;

    std::cout << "First name: ", std::getline(std::cin, first_name);
    std::cout << "Last name: ", std::getline(std::cin, last_name);
    std::cout << "Nickname: ", std::getline(std::cin, nickname);
    std::cout << "Phone number: ", std::getline(std::cin, phone_number);
    std::cout << "Secret: ", std::getline(std::cin, secret);

    if (first_name.empty() || last_name.empty() || phone_number.empty()
        || secret.empty() || nickname.empty())
        {
            std::cout << "Error: Fields can't be empty!" << std::endl;
            return ;
        }

    this->setContact(this->getCurrentIndex() % max_contacts,
		Contact(first_name, last_name, nickname, phone_number, secret));
    this->setCurrentIndex(this->getCurrentIndex() + 1);

    if (this->getNbContacts() < max_contacts)
        this->setNbContacts(this->getNbContacts() + 1);
}
