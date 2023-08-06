#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	std::cout << CAT_COLOR << "Cat";
	std::cout << WHITE << " class call default constructor." << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Brain& brain) : Animal()
{
	std::cout << CAT_COLOR << "Cat";
	std::cout << WHITE << " class call constructor." << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
	*this->brain = brain;
}

Cat::Cat(const Cat& cat) : Animal()
{
	std::cout << CAT_COLOR << "Cat";
	std::cout << WHITE << " class call constructor." << std::endl;
	this->brain = new Brain();
	*this = cat;
}

Cat::~Cat()
{
	if (this->brain)
		delete this->brain;
	std::cout << CAT_COLOR << "Cat";
	std::cout << WHITE << " class call destructor." << std::endl;
}

Cat& Cat::operator=(const Cat& cat)
{
	if (this != &cat)
	{
		this->type = cat.type;
		*this->brain = *cat.brain;
	}
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Meow! 🐱" << std::endl;
}

void	Cat::setBrain(const Brain& brain)
{
	*this->brain = brain;
}

void	Cat::think() const
{
	std::cout << "Cat think... 💭" << std::endl;
	brain->displayIdeas();
}