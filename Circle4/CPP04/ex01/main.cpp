#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>
#include <cstdlib>

void	leaks()
{
	system("leaks animal");
}

int main()
{
	// atexit(leaks);
	std::cout << "---------------TEST1---------------" << std::endl;
	// Basic
	{
		const Animal *dog = new Dog();
		const Animal *cat = new Cat();

		delete dog;
		delete cat;
	}
	std::cout << std::endl;
	std::cout << "---------------TEST2---------------" << std::endl;
	// Allocate Animal array
	{
		Animal	*animals[10];
		int		idx;

		for (idx = 0; idx < 5; idx++)
			animals[idx] = new Dog();
		for (idx = 5; idx < 10; idx++)
			animals[idx] = new Cat();

		for (idx = 0; idx < 10; idx++)
		{
			std::cout << idx << " : ";
			animals[idx]->makeSound();	
		}
		
		for (idx = 0; idx < 10; idx++)
			delete animals[idx];
	}
	std::cout << std::endl;
	std::cout << "---------------TEST3---------------" << std::endl;
	// Check deep copy
	{
		Brain	brain;
		
		brain.addIdea("Hello!!");
		brain.addIdea("I`m very hungry.");
		
		Dog		dog(brain);
		Dog		puppy(dog);
		
		brain.addIdea("And sleep too...");
		puppy.setBrain(brain);
		dog.think();
		puppy.think();
		
		Cat	cat(brain);
		
		cat.think();
	}
	std::cout << std::endl;
	return 0;
}