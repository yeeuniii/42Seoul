#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

template <typename T>
void print(T &container, typename T::iterator itr)
{
	for (; itr != container.end(); itr++)
		std::cout << *itr << std::endl;
}

void	testVector()
{
	std::cout << "=====vector=====" << std::endl;
	{
		std::vector<int> vec;

		vec.push_back(1);
		vec.push_back(10);
		vec.push_back(20);
		vec.push_back(30);
		vec.push_back(1);
		
		std::cout << "-----find-----" << std::endl;
		try
		{
			std::vector<int>::iterator itr;
			itr = easyfind(vec, 1);
			print(vec, itr);
			// itr = easyfind(vec, 1);
			// print(vec, itr);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "-----not find-----" << std::endl;
		try
		{
			std::vector<int>::iterator itr;
			itr = easyfind(vec, -2);
			print(vec, itr);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
}

void	testList()
{
	std::cout << "=====list=====" << std::endl;
	{
		std::list<int> lst;

		lst.push_back(1);
		lst.push_back(10);
		lst.push_back(20);
		lst.push_back(30);
		lst.push_back(2);

		std::cout << "-----find-----" << std::endl;
		try
		{
			std::list<int>::iterator itr;
			itr = easyfind(lst, 20);
			print(lst, itr);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "-----not find-----" << std::endl;
		try
		{
			std::list<int>::iterator itr;
			itr = easyfind(lst, -1);
			print(lst, itr);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
}

void	testDeque()
{
	std::cout << "=====deque=====" << std::endl;
	{
		std::deque<int> deq;

		deq.push_back(-2);
		deq.push_back(5);
		deq.push_back(11);

		std::cout << "-----find-----" << std::endl;
		try
		{
			std::deque<int>::iterator itr;
			itr = easyfind(deq, 5);
			print(deq, itr);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "-----not find-----" << std::endl;
		try
		{
			std::deque<int>::iterator itr;
			itr = easyfind(deq, 20);
			print(deq, itr);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}

int main()
{
	testVector();
	testList();
	testDeque();
	return 0;
}
