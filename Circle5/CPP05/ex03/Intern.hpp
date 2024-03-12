#ifndef __INTERN_HPP__
#define __INTERN_HPP__

#include "AForm.hpp"
#include <exception>

class Intern
{
	private:
		class MakingFormException : public std::exception
		{
			private:
				const char*	message;

			public:
				MakingFormException(std::string formName);
				virtual ~MakingFormException() throw();
				virtual const char*	what() const throw();
		};

	public:
		Intern();
		Intern(const Intern &intern);
		~Intern();
		Intern&	operator=(const Intern &intern);

		AForm*	makeForm(const std::string &formName, const std::string &formTarget) const;
};

#endif