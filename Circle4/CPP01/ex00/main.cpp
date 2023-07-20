#include "Zombie.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "----------BASIC----------" << std::endl;
	Zombie	zombie1;
	Zombie	zombie2("Foo");
	zombie1.announce();
	zombie2.announce();

	std::cout << std::endl;
	std::cout << "----------NEW ZOMBIE----------" << std::endl;
	Zombie	*zombie3 = newZombie("asdf");
	zombie3->announce();
	delete zombie3;
	
	std::cout << std::endl;
	std::cout << "----------RANDOM CHUMP----------" << std::endl;
	randomChump("random");

	return 0;
}
