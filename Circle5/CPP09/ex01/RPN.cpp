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
	
	if (size % 2 == 0)
		throw (SyntaxError());
	while (expression.size())
	{
		handleSyntaxError(expression.front());
		expression.pop();
	}
}

void	RPN::handleSyntaxError(const std::string& value)
{
	if (!isValidSyntax(value))
		throw (SyntaxError());
}

bool	RPN::isValidSyntax(const std::string& value)
{
	return (value.size() == 1
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
		(getOperationFunction(value))(stack);
		calculate(expression, stack);
		return ;
	}
	if (isdigit(value[0]))
	{
		stack.push(convertFloat(value));
		calculate(expression, stack);
	}
}

void (*RPN::getOperationFunction(const std::string& operation))(std::stack<float>&)
{
	if (operation == "+")
		return RPN::add;
	if (operation == "-")
		return RPN::subtract;
	if (operation == "/")
		return RPN::divide;
	return RPN::multiply;
}

void	RPN::add(std::stack<float>& stack)
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

void	RPN::subtract(std::stack<float>& stack)
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

void	RPN::divide(std::stack<float>& stack)
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

void	RPN::multiply(std::stack<float>& stack)
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
		if (!line.empty())
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