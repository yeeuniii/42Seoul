#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(): type("WrongAnimal")
{
	std::cout << ANIMAL_COLOR << "WrongAnimal";
	std::cout << WHITE << " class call default constructor." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& animal)
{
	std::cout << ANIMAL_COLOR << "WrongAnimal";
	std::cout << WHITE << " class call constructor." << std::endl;
	*this = animal;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << ANIMAL_COLOR << "WrongAnimal";
	std::cout << WHITE << " class call destructor." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& animal)
{
	if (this != &animal)
	{
		this->type = animal.type;
	}
	return *this;
}

const std::string&	WrongAnimal::getType() const
{
	return this->type;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Blabla" << std::endl;
}