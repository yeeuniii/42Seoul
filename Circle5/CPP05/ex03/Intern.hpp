#ifndef __INTERN_HPP__
#define __INTERN_HPP__

#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &intern);
		~Intern();
		Intern&	operator=(const Intern &intern);

		AForm*	makeForm(const std::string &formName, const std::string &formTarget) const;
};

#endif