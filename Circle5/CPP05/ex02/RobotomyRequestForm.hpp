#ifndef __ROBOTOMYREQUESTFORM_HPP__
#define __ROBOTOMYREQUESTFORM_HPP__

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
	private:
		std::string	target;
		
		RobotomyRequestForm();

	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &form);
		~RobotomyRequestForm();
		RobotomyRequestForm&	operator=(const RobotomyRequestForm &form);

		const std::string&	getTarget() const;
};

#endif