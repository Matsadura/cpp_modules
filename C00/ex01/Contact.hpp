/**
 * Contact.hpp
 * Header file for the Contact class.
 * This class represents a contact with personal details.
 * It includes methods to get and set contact information.
 */
#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>

/**
 * Contact: class to represent a contact with personal details.
 * @Methods: getFirstName, getLastName, getNickname, getPhoneNumber, getSecret,
 *          setFirstName, setLastName, setNickname, setPhoneNumber, setSecret.
 * @Attributes: _first_name, _last_name, _nickname, _phone_number, _darkest_secret.
 */
class Contact
{
public:
	Contact(void);
	Contact(
		const std::string &first,
		const std::string &last,
	 	const std::string &nick,
		const std::string &number,
		const std::string &secret
	);
	~Contact(void);

	std::string getFirstName(void) const;
	std::string getLastName(void) const;
	std::string getNickname(void) const;
	std::string getPhoneNumber(void) const;
	std::string getSecret(void) const;

	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setNickname(std::string Nickname);
	void setPhoneNumber(std::string Number);
	void setSecret(std::string DarkestSecret);

private:
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;

};

#endif /* CONTACT_H */