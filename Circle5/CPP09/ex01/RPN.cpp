#include "RPN.hpp"
#include <queue>
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

int	RPN::run(const std::string& argument)
{
	// std::queue<int>			queue;
	std::queue<std::string>	expression = split(argument, ' ');

	try
	{
		checkSyntax(expression);
		// calculate(expression, queue);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 1;
}

void	RPN::checkSyntax(std::queue<std::string> expression)
{
	unsigned int	size = expression.size();
	unsigned int	idx = 0;
	
	if (size % 2 == 0)
		throw (SyntaxError());
	handleSyntaxError(expression.front(), 1);
	expression.pop();
	while (++idx < size)
	{
		handleSyntaxError(expression.front(), idx);	
		expression.pop();
	}
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

int		convertInteger(std::string string)
{
	std::stringstream	ss;
	int		_int;

	ss << string;
	ss >> _int;
	return _int;
}
