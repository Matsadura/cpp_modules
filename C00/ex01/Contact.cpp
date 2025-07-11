#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::Contact(const std::string &first, const std::string &last,  const std::string &nick,
	const std::string &number, const std::string &secret)
{
    this->setFirstName(first);
    this->setLastName(last);
    this->setNickname(nick);
    this->setPhoneNumber(number);
    this->setSecret(secret);
}

Contact::~Contact(void)
{
}

std::string Contact::getFirstName(void) const
{
    return (this->_first_name);
}

void Contact::setFirstName(std::string first)
{
    this->_first_name = first;
}

std::string Contact::getLastName(void) const
{
    return (this->_last_name);
}

void Contact::setLastName(std::string last)
{
    this->_last_name = last;
}

std::string Contact::getNickname(void) const
{
    return (this->_nickname);
}

void Contact::setNickname(std::string nick)
{
    this->_last_name = nick;
}

std::string Contact::getPhoneNumber(void) const
{
    return (this->_phone_number);
}

void Contact::setPhoneNumber(std::string number)
{
    this->_phone_number = number;
}

std::string Contact::getSecret(void) const
{
    return (this->_darkest_secret);
}

void Contact::setSecret(std::string secret)
{
    this->_darkest_secret = secret;
}
