#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ): AForm("RobotomyRequestForm", 72, 45), _target("Robotomy")
{
	std::cout << "RobotomyRequestForm default constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm( const std::string& target ): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm parametrized constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other ): AForm(other), _target(other._target)
{
	std::cout << "RobotomyRequestForm copy constructor called\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& other )
{
	std::cout << "RobotomyRequestForm assignement operator called\n";
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout << "RobotomyRequestForm destructor called\n";
}

void	RobotomyRequestForm::execute( const Bureaucrat& executor ) const
{
	if (this->getSign() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeExecute())
		throw AForm::GradeTooLowException();
	
	srand(time(NULL));
	int random = rand() % 2;
	if (random == 0)
		std::cout << "Noise... " << this->_target << " robotomy failed.\n";
	else
		std::cout << "Noise... " << this->_target << " has been robotomized successfully 50% of the time.\n";
}