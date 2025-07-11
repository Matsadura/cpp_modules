#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H

#include "Contact.hpp"

class PhoneBook
{
public:
    PhoneBook(void);
    ~PhoneBook(void);
    
    int nbContacts;
    
    int addContact(Contact contacts[8], std::string input);
    
private:
    Contact _contacts[8];
};

#endif /* PHONE_BOOK_H */