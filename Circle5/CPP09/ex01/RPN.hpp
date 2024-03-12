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
		static bool	isValidSyntax(const std::string&);
		
		static void	calculate(std::queue<std::string>&, std::stack<float>&);
		static void (*getOperationFunction(const std::string& operation))(std::stack<float>&);
		static void	add(std::stack<float>&);
		static void	subtract(std::stack<float>&);
		static void	divide(std::stack<float>&);
		static void	multiply(std::stack<float>&);
	
	public:
		~RPN();
		RPN&	operator=(const RPN& rpn);

		static float	getSolution(const std::string&);
};

std::queue<std::string>	split(const std::string&, const char&);
bool	isOperator(const char&);
float	convertFloat(std::string string);

#endif