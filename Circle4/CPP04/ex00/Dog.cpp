#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << DOG_COLOR << "Dog";
	std::cout << WHITE << " class call default constructor." << std::endl;
}

Dog::Dog(const Dog& dog) : Animal()
{
	*this = dog; 
	std::cout << DOG_COLOR << "Dog";
	std::cout << WHITE << " class call constructor." << std::endl;
}

Dog::~Dog()
{
	std::cout << DOG_COLOR << "Dog";
	std::cout << WHITE << " class call destructor." << std::endl;
}

Dog& Dog::operator=(Dog const& dog)
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