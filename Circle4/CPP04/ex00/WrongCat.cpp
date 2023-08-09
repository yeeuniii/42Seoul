#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << CAT_COLOR << "WrongCat";
	std::cout << WHITE << " class call default constructor." << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& cat) : WrongAnimal()
{
	std::cout << CAT_COLOR << "WrongCat";
	std::cout << WHITE << " class call constructor." << std::endl;
	*this = cat; 
}

WrongCat::~WrongCat()
{
	std::cout << CAT_COLOR << "WrongCat";
	std::cout << WHITE << " class call destructor." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& cat)
{
	if (this != &cat)
	{
		this->type = cat.type;
	}
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "Meow! 🐱" << std::endl;
}