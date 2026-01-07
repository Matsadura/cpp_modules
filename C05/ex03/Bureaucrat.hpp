#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat( void );
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat( void );

		const std::string	getName( void ) const;
		int					getGrade( void ) const;
		void				incrementGrade( void );
		void				decrementGrade( void );
		void				signForm(AForm& form);

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

		void				executeForm(const AForm& form) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat&  bureau);

#endif /* BUREAURCRAT_HPP */