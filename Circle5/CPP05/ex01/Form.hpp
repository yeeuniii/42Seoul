#ifndef __FORM_HPP__
#define __FORM_HPP__

#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	private:
		const std::string name;
		bool			isSigned;
		const int		signableGrade;
		const int		executableGrade;
	
		Form();
		void	handleGradeException() const;
		void	handleHighGradeException() const;
		void	handleLowGradeException() const;
		bool	isHighGrade() const;
		bool	isLowGrade() const;

	public:
		Form(std::string name, int signableGrade, int executableGrade);
		Form(const Form& form);
		~Form();
		Form& operator=(const Form& form);

		const std::string&	getName() const;
		const bool&			getIsSigned() const;
		const int&			getSignableGrade() const;
		const int&			getExecutableGrade() const;		

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		void	beSigned(Bureaucrat bureaucrat);
};

std::ostream&	operator<<(std::ostream &out, const Form &form);

#endif