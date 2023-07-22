#include "Weapon.hpp"
#include <iostream>

int	main()
{
	Weapon	club = Weapon("crude spiked club");

	std::cout << club.getType() << std::endl;
	club.setType("some other type of club");
	std::cout << club.getType() << std::endl;


	return 0;
}