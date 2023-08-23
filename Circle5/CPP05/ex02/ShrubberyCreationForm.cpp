#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("shrubbery creation", 145, 137)
{
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form)
: AForm(form)
{
	*this = form;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form)
{
	if (this != &form)
	{
		this->target = form.target;
	}
	return *this;
}

const std::string&	ShrubberyCreationForm::getTarget() const
{
	return this->target;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::ofstream	file;
	
	checkExecute(executor.getGrade());
	try
	{
		file.open(this->target + "_shrubbery");
		if (file.is_open() == false)
			throw false;
		std::string	tree = makeAsciiTree();
		file.write(tree.c_str(), tree.size());
		file.close();
	}
	catch (bool is_open)
	{
		std::cerr << "Fail open file." << std::endl;
	}
}

std::string		ShrubberyCreationForm::makeAsciiTree() 
{
	std::string tree = "                          	   # #### ####\n \
	                       ### \\/#|### |/####\n \
 	                      ##\\/#/ \\||/##/_/##/_#\n \
  	                      ###  \\/###|/ \\/ # ###\n \
   	                 ##_\\_#\\_\\## | #/###_/_####\n \
    	               ## #### # \\ #| /  #### ##/##\n \
     	               __#_--###`  |{,###---###-~\n \
      	                        \\ }{\n \
    	                          }}{\n \
    	                          }}{\n \
     	                          {{}\n \
                    	    , -=-~{ .-^- _\n";
	return tree;
}