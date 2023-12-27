#ifndef __PRESIDENTIALPARDONFORM_HPP__
#define __PRESIDENTIALPARDONFORM_HPP__

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
	private:
		std::string	target;
		
		PresidentialPardonForm();

	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &form);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm&	operator=(const PresidentialPardonForm &form);

		const std::string&	getTarget() const;
		
		virtual void	execute(Bureaucrat const &executor) const;
};

#endif