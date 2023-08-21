#ifndef __SHRUBBERYCREATIONFORM_HPP__
#define __SHRUBBERYCREATIONFORM_HPP__

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	target;
		
		ShrubberyCreationForm();

	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &form);
		~ShrubberyCreationForm();
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm &form);

		const std::string&	getTarget() const;
};

#endif