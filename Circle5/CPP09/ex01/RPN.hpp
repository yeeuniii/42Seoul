#ifndef __RPN_HPP__
#define __RPN_HPP__

#include <string>
#include <stack>
#include <exception>

class RPN
{
	private:
		RPN();
		RPN(const RPN& rpn);

		static void	checkSyntax(std::stack<std::string>);
		static void	handleSyntaxError(const std::string&, const int&);
		static bool	isSyntaxError(const std::string&, const int&);
		
		class SyntaxError : public std::exception
		{
			public:
				const char*	what() const throw();
		};
	
	public:
		~RPN();
		RPN&	operator=(const RPN& rpn);

		static int	calculate(const std::string&);
};

std::stack<std::string>	split(const std::string&, const char&);
bool	isOperator(const char&);
int		convertInteger(std::string);

#endif