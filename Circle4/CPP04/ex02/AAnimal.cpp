#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal(): type("AAnimal")
{
	std::cout << AANIMAL_COLOR << "AAnimal";
	std::cout << WHITE << " class call default constructor." << std::endl;
}

AAnimal::AAnimal(const AAnimal& AAnimal)
{
	std::cout << AANIMAL_COLOR << "AAnimal";
	std::cout << WHITE << " class call constructor." << std::endl;
	*this = AAnimal;
}

AAnimal::~AAnimal()
{
	std::cout << AANIMAL_COLOR << "AAnimal";
	std::cout << WHITE << " class call destructor." << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& AAnimal)
{
	if (this != &AAnimal)
	{
		this->type = AAnimal.type;
	}
	return *this;
}

const std::string&	AAnimal::getType() const
{
	return this->type;
}