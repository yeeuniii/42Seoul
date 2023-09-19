#include "RPN.hpp"
#include <queue>
#include <sstream>
#include <cctype>
#include <iostream>
#include <stdexcept>

const char*	RPN::SyntaxError::what() const throw()
{
	return "Error: syntax error";
}

RPN::RPN() {}

RPN::RPN(const RPN& rpn)
{
	*this = rpn;
}

RPN::~RPN() {}

RPN&	RPN::operator=(const RPN& rpn)
{
	if (this != &rpn) {}
	return *this;
}

float	RPN::getSolution(const std::string& argument)
{
	std::stack<float>		stack;
	std::queue<std::string>	expression = split(argument, ' ');

	checkSyntax(expression);
	calculate(expression, stack);
	return stack.top();
}

void	RPN::checkSyntax(std::queue<std::string> expression)
{
	unsigned int	size = expression.size();
	unsigned int	idx = 0;
	
	if (size % 2 == 0)
		throw (SyntaxError());
	handleSyntaxError(expression.front());
	expression.pop();
	while (++idx < size)
	{
		handleSyntaxError(expression.front());
		expression.pop();
	}
}

void	RPN::handleSyntaxError(const std::string& value)
{
	if (isSyntaxError(value))
		throw (SyntaxError());
}

bool	RPN::isSyntaxError(const std::string& value)
{
	return !(value.size() == 1
		&& (isOperator(value[0]) || std::isdigit(value[0])));
}

void	RPN::calculate(std::queue<std::string>& expression, std::stack<float>& stack)
{
	std::string	value;

	if (expression.size() == 0)
		return ;
	value = expression.front();
	expression.pop();
	if (isOperator(value[0]))
	{
		handleOperator(stack, value);
		calculate(expression, stack);
		return ;
	}
	if (isdigit(value[0]))
	{
		stack.push(convertFloat(value));
		calculate(expression, stack);
		return ;
	}
}

void	RPN::handleOperator(std::stack<float>& stack, const std::string& operation)
{
	if (operation == "+")
	{
		handleAddition(stack);
		return ;
	}
	if (operation == "-")
	{
		handleSubtraction(stack);
		return ;
	}
	if (operation == "/")
	{
		handleDivision(stack);
		return ;
	}
	if (operation == "*")
	{
		handleMultiplication(stack);
		return ;
	}
}

void	RPN::handleAddition(std::stack<float>& stack)
{
	float	second;
	float	result;

	second = stack.top();
	stack.pop();
	result = stack.top();
	stack.pop();
	result += second;
	stack.push(result);
}

void	RPN::handleSubtraction(std::stack<float>& stack)
{
	float	second;
	float	result;

	second = stack.top();
	stack.pop();
	result = stack.top();
	stack.pop();
	result -= second;
	stack.push(result);
}

void	RPN::handleDivision(std::stack<float>& stack)
{
	float	second;
	float	result;

	second = stack.top();
	stack.pop();
	result = stack.top();
	stack.pop();
	if (second == 0)
		throw (std::overflow_error("Error: divide by zero exception."));
	result /= second;
	stack.push(result);
}

void	RPN::handleMultiplication(std::stack<float>& stack)
{
	float	second;
	float	result;

	second = stack.top();
	stack.pop();
	result = stack.top();
	stack.pop();
	result *= second;
	stack.push(result);
}

/* utils */

std::queue<std::string>	split(const std::string& string, const char& delimeter)
{
	std::stringstream		ss(string);
	std::string				line;
	std::queue<std::string>	destination;

	while (std::getline(ss, line, delimeter))
	{
		if (line[0])
			destination.push(line);
	}
	return destination;	
}

bool	isOperator(const char& c)
{
	return c == '+' || c == '-' || c == '/' || c == '*';
}

float	convertFloat(std::string string)
{
	std::stringstream ss;
	float	_float;
	
	ss << string;
	ss >> _float;
	return _float;
}