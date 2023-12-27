#include "AAnimal.hpp"
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
		const AAnimal *dog = new Dog();
		const AAnimal *cat = new Cat();

		delete dog;
		delete cat;
	}
	std::cout << std::endl;
	std::cout << "---------------TEST2---------------" << std::endl;
	// Allocate AAnimal array
	{
		AAnimal	*animals[10];
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
	// std::cout << "---------------TEST3---------------" << std::endl;
	// // Wrong case
	// {
	// 	AAnimal	aanimal;
	// }
	// std::cout << std::endl;
	return 0;
}