#ifndef __FORM_HPP__
#define __FORM_HOO__

#include <string>
#include <exception>

class Form
{
	private:
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
};

#endif