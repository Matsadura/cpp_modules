#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
	(void)other;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	std::cout << "Intern copy assignment operator called" << std::endl;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::makeShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makePresident(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	std::string names[3] = {
		"Shrubbery", "Robotomy", "Presidential"
	};
	AForm* (Intern::*types[3])(std::string) = {
		&Intern::makeShrubbery,
		&Intern::makeRobotomy,
		&Intern::makePresident 
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == names[i])
			return ((this->*types[i])(target));
	}
	std::cout << "Error: Form name: '" << formName << "' does not exist.\n";
	return (NULL);
}