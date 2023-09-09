#ifndef __MUTANTSTACK_HPP__
#define __MUTANTSTACK_HPP__

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	private:
	public:
		MutantStack();
		MutantStack(const MutantStack &stack);
		~MutantStack();
		MutantStack& operator=(const MutantStack &stack);
};

#include "MutantStack.tpp"

#endif