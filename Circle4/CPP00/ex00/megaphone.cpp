#include <iostream>

void	print_toupper(char *str)
{
	int	idx = 0;

	while (str[idx])
	{
		std::cout << char (toupper(str[idx]));
		idx++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int idx = 1; idx < argc; idx++)
		print_toupper(argv[idx]);
	std::cout << std::endl;
	return (0);
}
