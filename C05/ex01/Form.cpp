#include "Form.hpp"

Form::Form( void ): _name("Form"), _isSigned(false), _gradeSign(150), _gradeExecute(150)
{
	std::cout << "Form default constructor called\n";
}

Form::Form(std::string name, int gradeSin, int gradeExec): _name(name), _isSigned(false), _gradeSign(gradeSin), _gradeExecute(gradeExec)
{
	std::cout << "Parametrized Form constructor called\n";

	if (gradeSin < 1 || gradeExec < 1)
		throw Form::GradeTooHighException();
	if (gradeSin > 150 || gradeExec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other): _name(other._name), _isSigned(other._isSigned), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute)
{
	std::cout << "Form copy constructor called\n";
}

Form& Form::operator=(const Form& other)
{
	std::cout << "Form assignement operator called\n";
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}

Form::~Form( void )
{
	std::cout << "Form destructor called\n";
}

const std::string Form::getName( void ) const 
{
	return (this->_name);
}

bool Form::getSign( void ) const
{
	return (this->_isSigned);
}

int Form::getGradeSign( void ) const
{
	return (this->_gradeSign);
}

int Form::getGradeExecute( void ) const
{
	return (this->_gradeExecute);
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form: " << form.getName() 
		<< ", Signed?: " << form.getSign() 
		<< ", Grade to sign: " << form.getGradeSign() 
		<< ", Grade to execute: " << form.getGradeExecute();

	return (os);
}

void Form::beSigned( const Bureaucrat& bureau)
{
	if (bureau.getGrade() <= this->_gradeSign)
		this->_isSigned = true;
	else
		throw Form::GradeTooLowException();	
}