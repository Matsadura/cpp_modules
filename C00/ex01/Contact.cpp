/**
 * Contact.cpp
 * Implementation of the Contact class.
 * This class represents a contact with personal details.
 * It includes methods to get and set contact information.
 */
#include "Contact.hpp"

/**
 * Contact - Class constrctor
 */
Contact::Contact(void)
{
}

/**
 * Contact - Class constructor with parameters
 * @first: First name of the contact
 * @last: Last name of the contact
 * @nick: Nickname of the contact
 * @number: Phone number of the contact
 * @secret: Darkest secret of the contact
 */
Contact::Contact(const std::string &first, const std::string &last,  const std::string &nick,
	const std::string &number, const std::string &secret)
{
    this->setFirstName(first);
    this->setLastName(last);
    this->setNickname(nick);
    this->setPhoneNumber(number);
    this->setSecret(secret);
}

/**
 * Contact - Class destructor
 */
Contact::~Contact(void)
{
	this->_first_name.clear();
	this->_last_name.clear();
	this->_nickname.clear();
	this->_phone_number.clear();
	this->_darkest_secret.clear();
}

/**
 * getFirstName - Getter for first name
 * return: First name of the contact
 */
std::string Contact::getFirstName(void) const
{
    return (this->_first_name);
}

/**
 * setFirstName - Setter for first name
 * @first: First name to set
 */
void Contact::setFirstName(std::string first)
{
    this->_first_name = first;
}

/**
 * getLastName - Getter for last name
 * return: Last name of the contact
 */
std::string Contact::getLastName(void) const
{
    return (this->_last_name);
}

/**
 * setLastName - Setter for last name
 * @last: Last name to set
 */
void Contact::setLastName(std::string last)
{
    this->_last_name = last;
}

/**
 * getNickname - Getter for nickname
 * return: Nickname of the contact
 */
std::string Contact::getNickname(void) const
{
    return (this->_nickname);
}

/**
 * setNickname - Setter for nickname
 * @nick: Nickname to set
 */
void Contact::setNickname(std::string nick)
{
    this->_nickname = nick;
}

/**
 * getPhoneNumber - Getter for phone number
 * return: Phone number of the contact
 */
std::string Contact::getPhoneNumber(void) const
{
    return (this->_phone_number);
}

/**
 * setPhoneNumber - Setter for phone number
 * @number: Phone number to set
 */
void Contact::setPhoneNumber(std::string number)
{
    this->_phone_number = number;
}

/**
 * getSecret - Getter for darkest secret
 * return: Darkest secret of the contact
 */
std::string Contact::getSecret(void) const
{
    return (this->_darkest_secret);
}

/**
 * setSecret - Setter for darkest secret
 * @secret: Darkest secret to set
 */
void Contact::setSecret(std::string secret)
{
    this->_darkest_secret = secret;
}
