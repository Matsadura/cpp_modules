#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::Contact(const std::string &first, const std::string &last,
	const std::string &number, const std::string &secret)
{
    this->setFirstName(first);
    this->setLastName(last);
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
    if (first.empty() == false)
        this->_first_name = first;
    else
        std::cout << "First name can't be empty" << std::endl;
}

std::string Contact::getLastName(void) const
{
    return (this->_last_name);
}

void Contact::setLastName(std::string last)
{
    if (last.empty() == false)
        this->_last_name = last;
    else
        std::cout << "Last name can't be empty" << std::endl;
}

std::string Contact::getPhoneNumber(void) const
{
    return (this->_phone_number);
}

void Contact::setPhoneNumber(std::string number)
{
    if (number.empty() == false)
        this->_phone_number = number;
    else
        std::cout << "Phone number can't be empty" << std::endl;
}

std::string Contact::getSecret(void) const
{
    return (this->_darkest_secret);
}

void Contact::setSecret(std::string secret)
{
    if (secret.empty() == false)
        this->_darkest_secret = secret;
    else
        std::cout << "Darkest secret can't be empty" << std::endl;
}
