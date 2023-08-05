#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	std::cout << CAT_COLOR << "Cat";
	std::cout << WHITE << " class call default constructor." << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& cat) : Animal()
{
	std::cout << CAT_COLOR << "Cat";
	std::cout << WHITE << " class call constructor." << std::endl;
	*this = cat; 
}

Cat::~Cat()
{
	std::cout << CAT_COLOR << "Cat";
	std::cout << WHITE << " class call destructor." << std::endl;
}

Cat& Cat::operator=(const Cat& cat)
{
	if (this != &cat)
	{
		this->type = cat.type;
	}
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Meow! 🐱" << std::endl;
}