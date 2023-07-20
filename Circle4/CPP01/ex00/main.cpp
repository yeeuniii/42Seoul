#include "Zombie.hpp"
#include <iostream>

int	main(void)
{
	Zombie	zombie1;
	Zombie	zombie2("Foo");

	zombie1.announce();
	zombie2.announce();
	return 0;
}
