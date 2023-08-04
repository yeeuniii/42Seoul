#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal(), name("")
{
	this->type = "Dog";
	std::cout << DOG_COLOR << "Dog";
	std::cout << WHITE << " class call default constructor." << std::endl;
}

Dog::Dog(const std::string name) : Animal(), name(name)
{
	this->type = "Dog";
	std::cout << DOG_COLOR << "Dog";
	std::cout << WHITE << " class ";
	std::cout << DOG_COLOR << this->name;
	std::cout << WHITE << " call constructor." << std::endl;
}

Dog::Dog(const Dog& dog) : Animal()
{
	*this = dog; 
	std::cout << DOG_COLOR << "Dog";
	std::cout << WHITE << " class ";
	std::cout << DOG_COLOR << this->name;
	std::cout << WHITE << " call constructor." << std::endl;
}

Dog::~Dog()
{
	std::cout << DOG_COLOR << "Dog";
	std::cout << WHITE << " class ";
	std::cout << DOG_COLOR << this->name;
	std::cout << WHITE << " call destructor." << std::endl;
}

Dog& Dog::operator=(Dog const& dog)
{
	if (this != &dog)
	{
		this->name = dog.name;
		this->type = dog.type;
	}
	return *this;
}