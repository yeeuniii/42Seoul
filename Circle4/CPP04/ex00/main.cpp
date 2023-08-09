#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

void	leaks()
{
	system("leaks animal");
}

int main()
{
	atexit(leaks);
	std::cout << "---------------TEST1---------------" << std::endl;
	{
		const Animal *base = new Animal();
		const Animal *dog = new Dog();
		const Animal *cat = new Cat();
		std::cout << "Expected type is Dog : " << dog->getType() << std::endl;
		std::cout << "Expected type is Cat : " << cat->getType() << std::endl;
		dog->makeSound();
		cat->makeSound(); 
		base->makeSound();
		delete	base;
		delete	dog;
		delete	cat;
	}
	std::cout << std::endl;
	std::cout << "---------------TEST2---------------" << std::endl;
	{
		Animal	*animals[3];

		animals[0] = new Animal();
		animals[1] = new Cat();
		animals[2] = new Dog();
		for (int idx = 0; idx < 3; idx++)
		{
			std::cout << "Type is " << animals[idx]->getType()
					<< ", and make sound like this : ";
			animals[idx]->makeSound();
		}
		for (int idx = 0; idx < 3; idx++)
			delete animals[idx];
	}
	std::cout << std::endl;
	std::cout << "---------------Wrong Case---------------" << std::endl;
	{
		WrongAnimal*	animal = new WrongCat();
		WrongCat		cat;

		animal->makeSound();
		cat.makeSound();
		
		delete animal;
		std::cout << std::endl;
	}
	return 0;
}