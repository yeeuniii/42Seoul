#ifndef __ROBOTOMYREQUESTFORM_HPP__
#define __ROBOTOMYREQUESTFORM_HPP__

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
	private:
		std::string	target;
		
		RobotomyRequestForm();

	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &form);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm&	operator=(const RobotomyRequestForm &form);

		const std::string&	getTarget() const;
		virtual void		execute(Bureaucrat const &executor) const;
};

#endif