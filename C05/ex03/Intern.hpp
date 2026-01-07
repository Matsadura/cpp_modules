#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		AForm*	makeShrubbery(std::string target);
		AForm*	makeRobotomy(std::string target);
		AForm*	makePresident(std::string target);
		AForm* 	makeForm(const std::string& formName, const std::string& target);
};

#endif /* INTERN_HPP */