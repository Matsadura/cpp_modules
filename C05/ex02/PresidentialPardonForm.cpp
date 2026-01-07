#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ): AForm("PresidentialPardonForm", 25, 5), _target("President")
{
	std::cout << "PresidentialPardonForm default constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm( const std::string& target ): AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm parametrized constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other ): AForm(other), _target(other._target)
{
	std::cout << "PresidentialPardonForm copy constructor called\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& other )
{
	std::cout << "PresidentialPardonForm assignement operator called\n";
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout << "PresidentialPardonForm destructor called\n";
}

void	PresidentialPardonForm::execute( const Bureaucrat& executor ) const
{
	if (this->getSign() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeExecute())
		throw AForm::GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox.\n";
}