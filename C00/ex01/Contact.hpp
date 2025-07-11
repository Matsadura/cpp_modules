#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>

class Contact
{
public:
	Contact(void);
	Contact(
		const std::string &first,
		const std::string &last,
		const std::string &number,
		const std::string &secret
	);
	~Contact(void);

	std::string getFirstName(void) const;
	std::string getLastName(void) const;
	std::string getPhoneNumber(void) const;
	std::string getSecret(void) const;

	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setPhoneNumber(std::string Number);
	void setSecret(std::string DarkestSecret);

private:
	std::string _first_name;
	std::string _last_name;
	std::string _phone_number;
	std::string _darkest_secret;

};

#endif /* CONTACT_H */