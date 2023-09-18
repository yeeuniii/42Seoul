#ifndef __RPN_HPP__
#define __RPN_HPP__

#include <string>

class RPN
{
	private:
		RPN();
		RPN(const RPN& rpn);

		static bool	checkSyntax(const std::stack<std::string>&);
		
	
	public:
		~RPN();
		RPN&	operator=(const RPN& rpn);

		static int	calculate(const std::string&);
};

std::stack<std::string>	split(const std::string&, const char&);
int		convertInteger(std::string);

#endif