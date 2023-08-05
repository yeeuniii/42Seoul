#include "Animal.hpp"
#include <iostream>

Animal::Animal(): type("Animal")
{
	std::cout << ANIMAL_COLOR << "Animal";
	std::cout << WHITE << " class call default constructor." << std::endl;
}

Animal::Animal(const Animal& animal)
{
	std::cout << ANIMAL_COLOR << "Animal";
	std::cout << WHITE << " class call constructor." << std::endl;
	*this = animal;
}

Animal::~Animal()
{
	std::cout << ANIMAL_COLOR << "Animal";
	std::cout << WHITE << " class call destructor." << std::endl;
}

Animal& Animal::operator=(const Animal& animal)
{
	if (this != &animal)
	{
		this->type = animal.type;
	}
	return *this;
}

const std::string&	Animal::getType() const
{
	return this->type;
}

void	Animal::makeSound() const
{
	std::cout << "Blabla" << std::endl;
}