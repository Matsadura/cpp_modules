#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H

#include "Contact.hpp"

class PhoneBook
{
public:
    PhoneBook(void);
    ~PhoneBook(void);
    
    int nbContacts;
    
    void addContact(void);
    Contact getContact(int index) const;
    void    displayContacts(void) const;
    
private:
    Contact _contacts[8];
    int     _currentIndex;
    static int  max_contacts;
};

#endif /* PHONE_BOOK_H */