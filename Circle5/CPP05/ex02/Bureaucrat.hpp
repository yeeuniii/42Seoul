#pragma once
#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <string>
#include <exception>
#include "AForm.hpp"
#include <stdexcept>

class	AForm;

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

		void	signForm(AForm &form) const;
		void	executeForm(AForm const &form);
};

std::ostream&	operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif