#include <sstream>
#include <cctype>

int		convertStrToInt(std::string string)
{
	int		num;

	std::stringstream ss(string);
	ss >> num;
	return num;
}

bool	isDigitString(std::string string)
{
	int idx = 0;

	while (idx < (int)string.size() && isdigit(string[idx]))
		idx++;
	return (idx == (int)string.size());
}

bool	isWhitespaceString(std::string string)
{
	int idx = 0;

	while (idx < (int)string.size() && isspace(string[idx]))
		idx++;
	return (idx == (int)string.size());
}

