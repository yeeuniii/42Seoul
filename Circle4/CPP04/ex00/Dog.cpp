#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	std::cout << DOG_COLOR << "Dog";
	std::cout << WHITE << " class call default constructor." << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog& dog) : Animal()
{
	std::cout << DOG_COLOR << "Dog";
	std::cout << WHITE << " class call constructor." << std::endl;
	*this = dog; 
}

Dog::~Dog()
{
	std::cout << DOG_COLOR << "Dog";
	std::cout << WHITE << " class call destructor." << std::endl;
}

Dog& Dog::operator=(const Dog& dog)
{
	if (this != &dog)
	{
		this->type = dog.type;
	}
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Bark! 🐶" << std::endl;
}