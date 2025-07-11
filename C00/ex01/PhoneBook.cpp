#include "PhoneBook.hpp"

int PhoneBook::max_contacts = 8;

PhoneBook::PhoneBook(void)
{
    this->nbContacts = 0;
    this->_currentIndex = 0;
}

PhoneBook::~PhoneBook(void)
{
}

Contact PhoneBook::getContact(int index) const
{
    if (index < 0 && index > this->nbContacts)
        return (Contact());
    return (this->_contacts[index]);
}

void    PhoneBook::displayContacts(void) const
{
    int i;

    for (i = 0; i < this->nbContacts; i++)
    {
        Contact contact = this->getContact(i);
        std::cout << contact.getFirstName() + " | " + contact.getLastName() + " | " + contact.getNickname() + " | " + contact.getPhoneNumber() << std::endl;
    }

}

void PhoneBook::addContact(void)
{
    std::string first_name, last_name, nickname, phone_number, secret;

    std::cout << "First name: ", std::cin >> first_name;
    std::cout << "Last name: ", std::cin >> last_name;
    std::cout << "Nickname: ", std::cin >> nickname;
    std::cout << "Phone number: ", std::cin >> phone_number;
    std::cout << "Secret: ", std::cin >> secret;
    if (first_name.empty() || last_name.empty() || phone_number.empty()
        || secret.empty() || nickname.empty())
        {
            std::cout << "Error: Fields can't be empty!" << std::endl;
            return ;
        }
    this->_contacts[this->_currentIndex % max_contacts] = Contact(first_name, last_name, nickname, phone_number, secret);
    this->_currentIndex++;
    if (this->nbContacts < max_contacts)
        this->nbContacts++;
}

