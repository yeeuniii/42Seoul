#include "iter.hpp"
#include <iostream>

void	plusTen(int n)
{
	n += 10;
	std::cout << n << std::endl;
}

template <typename T>
void	print(T value)
{
	std::cout << value << std::endl;
}

template <typename T>
struct	printer
{
	void	operator()(T value)
	{
		std::cout << value << std::endl;
	}
};

int	main()
{
	std::cout << "-----Int array-----" << std::endl;
	{
		int	arr[3] = {0, 1, 2};
		printer<int> printInt;

		iter(arr, 3, plusTen); // function pointer
		iter(arr, 3, print<int>); // function template
		iter(arr, 3, printInt); // function object
		iter(arr, 3, printer<int>()); // function temporary object
	}
	std::cout << "-----Char* array-----" << std::endl;
	{
		const char*	arr[3] = {"hi", "hello", "bye"};

		iter(arr, 3, print<const char*>); // function template
		iter(arr, 3, printer<const char*>()); // function temporary object
	}

	return 0;
}