#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <cctype>
#include <iostream>

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

int	RPN::calculate(const std::string& argument)
{
	std::stack<int>			stack;
	std::stack<std::string>	expression = split(argument, ' ');

	try
	{
		checkSyntax(expression);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 1;
}

void	RPN::checkSyntax(std::stack<std::string> expression)
{
	unsigned int	size = expression.size();
	unsigned int	idx = size;
	std::string		value;
	
	if (size % 2 == 0)
		throw (SyntaxError());
	while (--idx > 0)
	{
		value = expression.top();
		handleSyntaxError(value, idx);	
		expression.pop();
	}
	value = expression.top();
	handleSyntaxError(value, 1);	
}

void	RPN::handleSyntaxError(const std::string& value, const int& index)
{
	if (isSyntaxError(value, index))
		throw (SyntaxError());
}

bool	RPN::isSyntaxError(const std::string& value, const int& index)
{
	return value.size() != 1
		|| (index % 2 == 0 && isOperator(value[0]) == false)
		|| (index % 2 == 1 && std::isdigit(value[0]) == false);
}

std::stack<std::string>	split(const std::string& string, const char& delimeter)
{
	std::stringstream		ss(string);
	std::string				line;
	std::stack<std::string>	destination;

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

int		convertInteger(std::string string)
{
	std::stringstream	ss;
	int		_int;

	ss << string;
	ss >> _int;
	return _int;
}
