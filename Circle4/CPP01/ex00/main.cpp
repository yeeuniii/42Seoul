#include "Zombie.hpp"
#include <iostream>

int	main(void)
{
	Zombie	zombie1;
	Zombie	zombie2("Foo");
	Zombie	*zombie3 = newZombie("asdf");

	zombie1.announce();
	zombie2.announce();
	zombie3->announce();
	
	delete zombie3;
	return 0;
}
