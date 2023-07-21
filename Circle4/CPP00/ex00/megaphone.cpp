#include <iostream>
#include <cctype>

std::string	getUpperCaseString(char *str)
{
	int			idx = 0;
	std::string	new_str;

	while (str[idx])
	{
		new_str += toupper(str[idx]); 
		idx++;
	}
	return new_str;
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int idx = 1; idx < argc; idx++)
		std::cout << getUpperCaseString(argv[idx]);
	std::cout << std::endl;
	return (0);
}
