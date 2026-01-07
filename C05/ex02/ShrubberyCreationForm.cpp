#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ): AForm("ShrubberyCreationForm", 145, 137), _target("Shrubbery")
{
	std::cout << "ShrubberyCreationForm default constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target ): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm parametrized constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other ): AForm(other), _target(other._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other )
{
	std::cout << "ShrubberyCreationForm assignement operator called\n";
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << "ShrubberyCreationForm destructor called\n";
}

void	ShrubberyCreationForm::execute( const Bureaucrat& executor ) const
{
	if (this->getSign() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeExecute())
		throw AForm::GradeTooLowException();
	
	std::ofstream outfile((this->_target + "_shrubbery").c_str());
	if (!outfile)
	{
		std::cerr << "Error creating file: " << this->_target + "_shrubbery" << std::endl;
		return;
	}

	outfile << "       _-_\n"
			   "    /~~   ~~\\\n"
			   " /~~         ~~\\\n"
			   "{               }\n"
			   " \\  _-     -_  /\n"
			   "   ~  \\\\ //  ~\n"
			   "_- -   | | _- _\n"
			   "  _ -  | |   -_\n"
			   "      // \\\\\n";
	outfile.close();
}