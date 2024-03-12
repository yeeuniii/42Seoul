#include "Dog.hpp"
#include <iostream>

Dog::Dog() : AAnimal()
{
	std::cout << DOG_COLOR << "Dog";
	std::cout << WHITE << " class call default constructor." << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Brain& brain) : AAnimal()
{
	std::cout << DOG_COLOR << "Dog";
	std::cout << WHITE << " class call constructor." << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
	*this->brain = brain;
}

Dog::Dog(const Dog& dog) : AAnimal()
{
	std::cout << DOG_COLOR << "Dog";
	std::cout << WHITE << " class call constructor." << std::endl;
	this->brain = new Brain();
	*this = dog;	
}

Dog::~Dog()
{
	if (this->brain)
		delete this->brain;
	std::cout << DOG_COLOR << "Dog";
	std::cout << WHITE << " class call destructor." << std::endl;
}

Dog& Dog::operator=(const Dog& dog)
{
	if (this != &dog)
	{
		this->type = dog.type;
		*this->brain = *dog.brain;
	}
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Bark! 🐶" << std::endl;
}

void	Dog::setBrain(const Brain& brain)
{
	*this->brain = brain;
}

void	Dog::think() const
{
	std::cout << "Dog think... 💭" << std::endl;
	brain->displayIdeas();
}