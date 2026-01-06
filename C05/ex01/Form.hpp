#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>

# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeSign;
		const int			_gradeExecute;

	public:
		Form( void );
		Form(std::string name, int gradeSin, int gradeExec);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form( void );

		const std::string	getName( void ) const;
		bool				getSign( void ) const;
		int					getGradeSign( void ) const;
		int					getGradeExecute( void ) const;
		void				beSigned( const Bureaucrat& bureau);

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade Too High!");
				}
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade Too Low!");
				}
		};
};

std::ostream& operator<<(std::ostream& os, const Form&  bureau);

#endif /* FORM_HPP */