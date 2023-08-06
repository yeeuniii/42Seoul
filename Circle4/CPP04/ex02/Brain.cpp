#include "Brain.hpp"
#include <iostream>

Brain::Brain(): index(0)
{
	std::cout << BRAIN_COLOR << "Brain";
	std::cout << WHITE << " class call default constructor." << std::endl;
}

Brain::Brain(const Brain& brain): index(0)
{
	std::cout << BRAIN_COLOR << "Brain";
	std::cout << WHITE << " class call constructor." << std::endl;
	*this = brain;
}

Brain::~Brain()
{
	std::cout << BRAIN_COLOR << "Brain";
	std::cout << WHITE << " class call destructor." << std::endl;
}

Brain&	Brain::operator=(const Brain& brain)
{
	if (this == &brain)
		return *this;
	setIdeas(brain.ideas);
	this->index = brain.index;
	return *this;
}

void	Brain::setIdeas(const std::string ideas[])
{
	for (int idx = 0; idx < 100; idx++)
		this->ideas[idx] = ideas[idx];
}

void	Brain::addIdea(const std::string idea)
{
	this->ideas[this->index] = idea;
	this->index++;
}

void	Brain::displayIdeas() const
{
	for (int idx = 0; idx < this->index; idx++)
		std::cout << this->ideas[idx] << std::endl; 
}