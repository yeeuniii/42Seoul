#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal(), name("")
{
	this->type = "Cat";
	std::cout << CAT_COLOR << "Cat";
	std::cout << WHITE << " class call default constructor." << std::endl;
}

Cat::Cat(const std::string name) : Animal(), name(name)
{
	this->type = "Cat";
	std::cout << CAT_COLOR << "Cat";
	std::cout << WHITE << " class ";
	std::cout << CAT_COLOR << this->name;
	std::cout << WHITE << " call constructor." << std::endl;
}

Cat::Cat(const Cat& cat) : Animal()
{
	*this = cat; 
	std::cout << CAT_COLOR << "Cat";
	std::cout << WHITE << " class ";
	std::cout << CAT_COLOR << this->name;
	std::cout << WHITE << " call constructor." << std::endl;
}

Cat::~Cat()
{
	std::cout << CAT_COLOR << "Cat";
	std::cout << WHITE << " class ";
	std::cout << CAT_COLOR << this->name;
	std::cout << WHITE << " call destructor." << std::endl;
}

Cat& Cat::operator=(Cat const& cat)
{
	if (this != &cat)
	{
		this->name = cat.name;
		this->type = cat.type;
	}
	return *this;
}