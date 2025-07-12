/**
 * PhoneBook.hpp
 * Header file for the PhoneBook class.
 * This class manages a collection of contacts.
 * It allows adding, retrieving, and displaying contacts.
 */
#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H

#include <iomanip>
#include <iostream>
#include <string>
#include <cstdlib>
#include "Contact.hpp"

/**
 * PhoneBook: class to manage a collection of contacts.
 * @Methods: addContact, getContact, searchContacts, displaySignleContact
 * 		setContact, getNbContacts, setNbContacts, getCurrentIndex, setCurrentIndex.
 * @Attributes: _contacts, _currentIndex, max_contacts.
 */
class PhoneBook
{
public:
    PhoneBook(void);
    ~PhoneBook(void);
    
    
    void 		addContact(void);
    Contact 	getContact(int index) const;
	void		setContact(int index, Contact contact);
    void    	searchContacts(void) const;
	void		displaySingleContact(void) const;
	int			getNbContacts(void) const;
	void		setNbContacts(int n);
	int			getCurrentIndex(void) const;
	void		setCurrentIndex(int n);
    
private:
    Contact 	_contacts[8];
    int			_nbContacts;
    int     	_currentIndex;
    static int  max_contacts;
	std::string formatField(const std::string& field) const;
};

#endif /* PHONE_BOOK_H */
