#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
	std::cout << "----------Subject`s test----------" << std::endl;
	{
		Span sp = Span(5);
		
		try
		{
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			std::cout << "The shortest span : " << sp.shortestSpan() << std::endl;
			std::cout << "The longest span : " << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "------------cannot unable save----------" << std::endl;
	{
		Span	sp(2);
		
		try
		{
			sp.addNumber(1);
			sp.addNumber(2);
			sp.addNumber(3);
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "------------cannot find span----------" << std::endl;
	{
		Span	sp(5);
	
		try
		{
			sp.shortestSpan();	
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			sp.addNumber(1);
			sp.longestSpan();	
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "----------call addNumber using iterator----------" << std::endl;
	{
		Span				sp(1000);
		std::vector<int>	vec;

		for (int idx = 0; idx < 1000; idx++)
			vec.push_back(idx);
		
		try
		{
			sp.addNumber(vec.begin(), vec.end());
			std::cout << "The shortest span : " << sp.shortestSpan() << std::endl;
			std::cout << "The longest span : " << sp.longestSpan() << std::endl;
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}