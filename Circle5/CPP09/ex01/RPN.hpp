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
		static void	handleSyntaxError(const std::string&);
		static bool	isSyntaxError(const std::string&);
		
		static void	calculate(std::queue<std::string>&, std::queue<int>&);
		static int	handleOperator(std::queue<int>&, const std::string&);
	
	public:
		~RPN();
		RPN&	operator=(const RPN& rpn);

		static int	run(const std::string&);
};

std::queue<std::string>	split(const std::string&, const char&);
bool	isOperator(const char&);
int		convertInteger(std::string);

#endif