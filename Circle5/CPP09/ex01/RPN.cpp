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
	std::queue<int>			queue;
	std::queue<std::string>	expression = split(argument, ' ');

	try
	{
		checkSyntax(expression);
		queue.push(convertInteger(expression.front()));
		expression.pop();
		calculate(expression, queue);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return queue.front();
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

void	RPN::calculate(std::queue<std::string>& expression, std::queue<int>& queue)
{
	if (expression.size() == 0)
		return ;
	queue.push(convertInteger(expression.front()));
	expression.pop();	
	queue.push(handleOperator(queue, expression.front()));
	expression.pop();
	calculate(expression, queue);
}

int		RPN::handleOperator(std::queue<int>& queue, const std::string& operation)
{
	int	value = queue.front();

	queue.pop();
	if (operation == "+")
	{
		value += queue.front();
		queue.pop();
		return value;
	}
	if (operation == "-")
	{
		value -= queue.front();
		queue.pop();
		return value;
	}
	if (operation == "/")
	{
		value /= queue.front();
		queue.pop();
		return value;
	}
	if (operation == "*")
	{
		value *= queue.front();
		queue.pop();
		return value;
	}
	return value;
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
