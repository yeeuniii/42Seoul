#include "Animal.hpp"
#include <iostream>

Animal::Animal(): type("")
{
	std::cout << ANIMAL_COLOR << "Animal";
	std::cout << WHITE << " class call default constructor." << std::endl;
}

Animal::Animal(const Animal& animal)
{
	*this = animal;
	std::cout << ANIMAL_COLOR << "Animal";
	std::cout << WHITE << " class call constructor." << std::endl;
}

Animal::~Animal()
{
	std::cout << ANIMAL_COLOR << "Animal";
	std::cout << WHITE << " class call destructor." << std::endl;
}

Animal& Animal::operator=(Animal const& animal)
{
	if (this != &animal)
	{
		this->type = animal.type;
	}
	return *this;
}