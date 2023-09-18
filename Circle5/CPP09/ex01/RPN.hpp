#ifndef __RPN_HPP__
#define __RPN_HPP__

#include <string>
#include <queue>
#include <stack>
#include <exception>

class RPN
{
	private:
		RPN();
		RPN(const RPN& rpn);

		class SyntaxError : public std::exception
		{
			public:
				const char*	what() const throw();
		};
		
		static void	checkSyntax(std::queue<std::string>);
		static void	handleSyntaxError(const std::string&, const int&);
		static bool	isSyntaxError(const std::string&, const int&);
		
		// static void	calculate(std::stack<std::string>&, std::stack<int>&);
		// static int	handleOperator();
	
	public:
		~RPN();
		RPN&	operator=(const RPN& rpn);

		static int	run(const std::string&);
};

std::queue<std::string>	split(const std::string&, const char&);
bool	isOperator(const char&);
int		convertInteger(std::string);

#endif