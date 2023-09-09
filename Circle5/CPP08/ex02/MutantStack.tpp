#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &stack) : std::stack<T>(stack)
{
	*this = stack;
}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack &stack)
{
	if (this != stack) {}
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return std::stack<T>::c.begin();
}
template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return std::stack<T>::c.end();
}