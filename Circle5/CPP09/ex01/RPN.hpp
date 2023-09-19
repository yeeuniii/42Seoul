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
		
		static void	calculate(std::queue<std::string>&, std::stack<float>&);
		static void	handleOperator(std::stack<float>&, const std::string&);
		static void	handleAddition(std::stack<float>&);
		static void	handleSubtraction(std::stack<float>&);
		static void	handleDivision(std::stack<float>&);
		static void	handleMultiplication(std::stack<float>&);
	
	public:
		~RPN();
		RPN&	operator=(const RPN& rpn);

		static float	run(const std::string&);
};

std::queue<std::string>	split(const std::string&, const char&);
bool	isOperator(const char&);
float	convertFloat(std::string string);

#endif