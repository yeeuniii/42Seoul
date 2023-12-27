#include "MutantStack.hpp"
#include <iostream>
#include <list>

template <typename T>
void testMutantStack(MutantStack<T> &mstack)
{
	mstack.push(5);
	mstack.push(17);
	mstack.pop();
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << "top: " << mstack.top() << std::endl;
	std::cout << "size: " << mstack.size() << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

template <typename T>
void testList(std::list<T> &lst)
{
	lst.push_back(5);
	lst.push_back(17);
	lst.pop_back();
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	// std::cout << "top: " << lst.top() << std::endl;
	std::cout << "size: " << lst.size() << std::endl;
	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

template <typename T>
void testMutantStackReverse(MutantStack<T> &mstack)
{
	mstack.push(0);
	mstack.push(1);
	mstack.push(10);
	mstack.push(100);
	mstack.push(1000);
	std::cout << "top: " << mstack.top() << std::endl;
	std::cout << "size: " << mstack.size() << std::endl;
	MutantStack<int>::reverse_iterator it = mstack.rbegin();
	MutantStack<int>::reverse_iterator ite = mstack.rend();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

int main()
{
	std::cout << "----------Mutant Stack----------" << std::endl;
	{
		MutantStack<int> mstack;
		testMutantStack(mstack);
	}
	std::cout << std::endl;
	std::cout << "----------List----------" << std::endl;
	{
		std::list<int> lst;
		testList(lst);
	}
	std::cout << std::endl;
	std::cout << "----------Reverse Iterator----------" << std::endl;
	{
		MutantStack<int> mstack;
		testMutantStackReverse(mstack);
	}
	return 0;
}