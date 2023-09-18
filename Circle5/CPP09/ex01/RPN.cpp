#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <cctype>

RPN::RPN() {}

RPN::RPN(const RPN& rpn)
{
	*this = rpn;
}

RPN::~RPN() {}

RPN&	RPN::operator=(const RPN& rpn)
{
	if (this != &rpn)
	{
	}
	return *this;
}

int	RPN::calculate(const std::string& argument)
{
	std::stack<int>	stack;
	std::stack<std::string>	expression = split(argument, ' ');

	checkSyntax(expression);
	return 1;
}

bool	RPN::checkSyntax(const std::stack<std::string>& expression)
{
	return true;
	(void)expression;
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

int		convertInteger(std::string string)
{
	std::stringstream	ss;
	int		_int;

	ss << string;
	ss >> _int;
	return _int;
}