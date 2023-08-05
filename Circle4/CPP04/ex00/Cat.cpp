#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << CAT_COLOR << "Cat";
	std::cout << WHITE << " class call default constructor." << std::endl;
}

Cat::Cat(const Cat& cat) : Animal()
{
	*this = cat; 
	std::cout << CAT_COLOR << "Cat";
	std::cout << WHITE << " class call constructor." << std::endl;
}

Cat::~Cat()
{
	std::cout << CAT_COLOR << "Cat";
	std::cout << WHITE << " class call destructor." << std::endl;
}

Cat& Cat::operator=(Cat const& cat)
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