#ifndef __AFORM_HPP__
#define __AFORM_HPP__

#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	private:
		AForm();

	protected:
		const std::string name;
		bool			isSigned;
		const int		signableGrade;
		const int		executableGrade;
	
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
		
		void	handleGradeException() const;
		void	handleHighGradeException() const;
		void	handleLowGradeException() const;
		bool	isHighGrade() const;
		bool	isLowGrade() const;

	public:
		AForm(std::string name, int signableGrade, int executableGrade);
		AForm(const AForm& form);
		~AForm();
		AForm& operator=(const AForm& form);

		const std::string&	getName() const;
		const bool&			getIsSigned() const;
		const int&			getSignableGrade() const;
		const int&			getExecutableGrade() const;		

		void	beSigned(Bureaucrat bureaucrat);
};

std::ostream&	operator<<(std::ostream &out, const AForm &form);

#endif