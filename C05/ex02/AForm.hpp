#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <stdexcept>

# include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeSign;
		const int			_gradeExecute;

	public:
		AForm( void );
		AForm(std::string name, int gradeSin, int gradeExec);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm( void );

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
		
		class FormNotSignedException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Form Not Signed!");
				}
		};

		virtual void		execute( const Bureaucrat& executor ) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm&  bureau);

#endif /* AFORM_HPP */