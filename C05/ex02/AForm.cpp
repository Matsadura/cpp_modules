#include "AForm.hpp"

AForm::AForm( void ): _name("AForm"), _isSigned(false), _gradeSign(150), _gradeExecute(150)
{
	std::cout << "AForm default constructor called\n";
}

AForm::AForm(std::string name, int gradeSin, int gradeExec): _name(name), _isSigned(false), _gradeSign(gradeSin), _gradeExecute(gradeExec)
{
	std::cout << "Parametrized AForm constructor called\n";

	if (gradeSin < 1 || gradeExec < 1)
		throw AForm::GradeTooHighException();
	if (gradeSin > 150 || gradeExec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other): _name(other._name), _isSigned(other._isSigned), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute)
{
	std::cout << "AForm copy constructor called\n";
}

AForm& AForm::operator=(const AForm& other)
{
	std::cout << "AForm assignement operator called\n";
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}

AForm::~AForm( void )
{
	std::cout << "AForm destructor called\n";
}

const std::string AForm::getName( void ) const 
{
	return (this->_name);
}

bool AForm::getSign( void ) const
{
	return (this->_isSigned);
}

int AForm::getGradeSign( void ) const
{
	return (this->_gradeSign);
}

int AForm::getGradeExecute( void ) const
{
	return (this->_gradeExecute);
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "AForm: " << form.getName() 
		<< ", Signed?: " << form.getSign() 
		<< ", Grade to sign: " << form.getGradeSign() 
		<< ", Grade to execute: " << form.getGradeExecute();

	return (os);
}

void AForm::beSigned( const Bureaucrat& bureau)
{
	if (bureau.getGrade() <= this->_gradeSign)
		this->_isSigned = true;
	else
		throw AForm::GradeTooLowException();	
}