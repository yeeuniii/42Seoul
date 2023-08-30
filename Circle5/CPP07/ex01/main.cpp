#include "iter.hpp"
#include <iostream>

void plusTen(int n)
{
	n += 10;
	std::cout << n << std::endl;
}

struct print
{
	template <typename T>
		void	operator()(T element)
		{
			std::cout << element << std::endl;
		}
};

int main()
{
	std::cout << "----------int array----------" << std::endl;
	{
		int *arr = new int[3];

		arr[0] = 1;
		arr[1] = 2;
		arr[2] = 3;
	
		::iter(&arr, 3, print());
		std::cout << std::endl;
		::iter(&arr, 3, &plusTen);
		
		delete[] arr;
	}
	std::cout << std::endl;
	std::cout << "----------char array----------" << std::endl;
	{
		char *arr = new char[4];

		arr[0] = 'a';
		arr[1] = 's';
		arr[2] = 'd';
		arr[3] = 'f';

		::iter(&arr, 4, print());
		
		delete[] arr;
	}
	return 0;
}