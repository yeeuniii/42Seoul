#ifndef __AFORM_HPP__
#define __AFORM_HPP__

#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	private:
		const std::string name;
		bool			isSigned;
		const int		signableGrade;
		const int		executableGrade;
	
		class GradeTooHighException : public std::exception
		{
			private:
				const char*	message;

			public:
				GradeTooHighException();
				GradeTooHighException(const char *message);
				virtual const char	*what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			private:
				const char*	message;
			
			public:
				GradeTooLowException();
				GradeTooLowException(const char *message);
				virtual const char	*what() const throw();
		};
		class NotSignException : public std::exception
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
		AForm();
		AForm(std::string name, int signableGrade, int executableGrade);
		AForm(const AForm& form);
		virtual ~AForm();
		AForm& operator=(const AForm& form);

		const std::string&	getName() const;
		const bool&			getIsSigned() const;
		const int&			getSignableGrade() const;
		const int&			getExecutableGrade() const;		

		void	beSigned(Bureaucrat bureaucrat);
		virtual void	execute(Bureaucrat const &executor) const = 0;
		void	checkExecute(int executorGrade) const;
};

std::ostream&	operator<<(std::ostream &out, const AForm &form);

#endif