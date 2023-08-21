#pragma once
#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <string>
#include <exception>
#include "Form.hpp"

class	Form;

class	Bureaucrat
{
	private:
		const std::string	name;
		int			grade;

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
		
		Bureaucrat();

		void	handleGradeException() const;
		void	handleHighGradeException() const;
		void	handleLowGradeException() const;
		bool	isHighGrade() const;
		bool	isLowGrade() const;
	
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &bureaucrat);
		~Bureaucrat();
		Bureaucrat&	operator=(const Bureaucrat &bureaucrat);

		const std::string&	getName() const;
		const int&			getGrade() const;

		void	incrementGrade(int grade);
		void	decrementGrade(int grade);

		void	signForm(const Form &form) const;
};

std::ostream&	operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif